#include <HTTPClient.h>
#include "config.h"
#include "auth.h"

String otp_sent = "";

void sendOTP() {
    otp_sent = String(random(1000, 9999));
    // Twilio sending logic can be implemented here
}

bool verifyOTP(String input){
    return input == otp_sent;
}
