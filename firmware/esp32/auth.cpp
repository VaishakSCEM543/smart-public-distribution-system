#include <HTTPClient.h>
#include "config.h"
#include "auth.h"

// --- OTP Configuration ---
#define OTP_EXPIRY_MS     120000UL  // OTP valid for 2 minutes (120,000 ms)
#define MAX_OTP_ATTEMPTS  3         // Lock out after 3 failed attempts

static String otp_sent      = "";
static unsigned long otp_generated_at = 0;
static int otp_attempts     = 0;

// Generates a 4-digit OTP and records the timestamp
void sendOTP() {
    randomSeed(millis());  // Seed with uptime for better randomness
    otp_sent = String(random(1000, 9999));
    otp_generated_at = millis();
    otp_attempts = 0;

    Serial.print("[Auth] OTP generated (not shown for security). Valid for ");
    Serial.print(OTP_EXPIRY_MS / 1000);
    Serial.println("s.");

    // TODO: send via Twilio SMS — credentials defined in config.h:
    //   TWILIO_SID, TWILIO_AUTH, TWILIO_FROM, USER_PHONE
}

// Verifies user-supplied OTP against the generated one.
// Returns AUTH_OK, AUTH_WRONG, AUTH_EXPIRED, or AUTH_LOCKED.
AuthResult verifyOTP(String input) {
    // Check lockout
    if (otp_attempts >= MAX_OTP_ATTEMPTS) {
        Serial.println("[Auth] LOCKED — max attempts reached.");
        return AUTH_LOCKED;
    }

    // Check expiry
    if (millis() - otp_generated_at > OTP_EXPIRY_MS) {
        Serial.println("[Auth] OTP expired.");
        return AUTH_EXPIRED;
    }

    // Check match
    if (input == otp_sent) {
        Serial.println("[Auth] OTP verified OK.");
        otp_attempts = 0;
        otp_sent = "";  // Invalidate after successful use
        return AUTH_OK;
    }

    otp_attempts++;
    Serial.print("[Auth] Wrong OTP. Attempt ");
    Serial.print(otp_attempts);
    Serial.print("/");
    Serial.println(MAX_OTP_ATTEMPTS);
    return AUTH_WRONG;
}

// Resets auth state — call after a session ends or on system reset
void resetAuth() {
    otp_sent = "";
    otp_generated_at = 0;
    otp_attempts = 0;
    Serial.println("[Auth] State reset.");
}
