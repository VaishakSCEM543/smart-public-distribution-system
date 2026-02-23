# System Workflow – Smart PDS

The Smart PDS workflow ensures controlled, automated ration dispensing.

---

## Step 1: User Authentication

User authenticates via:
- OTP
- QR
- Manual entry (depending on configuration)

---

## Step 2: Entitlement Verification

System verifies:
- User eligibility
- Remaining ration quota

---

## Step 3: Quantity Selection

User selects:
- Category (Grains, Pulses, etc.)
- Subcategory
- Quantity

---

## Step 4: Automated Dispensing

- Servo opens outlet
- Load cell continuously monitors weight
- Dispensing stops when target weight is reached

---

## Step 5: Transaction Logging

- Final weight recorded
- Data sent to Firebase
- Entry visible in web portal

---

## Step 6: System Reset

System returns to idle state for next user.
