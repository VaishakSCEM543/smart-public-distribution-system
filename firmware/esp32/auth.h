#ifndef AUTH_H
#define AUTH_H

// Result codes returned by verifyOTP()
enum AuthResult {
    AUTH_OK,       // OTP matched and is valid
    AUTH_WRONG,    // OTP did not match (attempt counted)
    AUTH_EXPIRED,  // OTP has passed the 2-minute expiry window
    AUTH_LOCKED    // Too many wrong attempts — session locked
};

void       sendOTP();
AuthResult verifyOTP(String input);
void       resetAuth();

#endif
