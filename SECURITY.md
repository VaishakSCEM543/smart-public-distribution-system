# Security Policy — Smart PDS

## Overview

Smart PDS handles sensitive beneficiary data and government ration distribution records. Security is a core design principle across all layers of the system — from firmware to cloud to web portals.

## Supported Versions

| Version | Status             | Notes                                    |
| ------- | ------------------ | ---------------------------------------- |
| v3.5.x  | ✅ Active Support   | Current release with all security fixes  |
| v3.0.x  | ⚠️ Limited Support | Critical patches only                    |
| < v3.0  | ❌ End of Life      | No longer maintained                     |

## Security Architecture

### 🔐 Data Transmission
- All ESP32-to-Firebase communication uses **HTTPS (TLS 1.2+)** encrypted channels.
- Web portals load Firebase SDK over **secure CDN endpoints**.
- No sensitive data is transmitted in plain text.

### 🛡️ Access Control
- **Role-Based Access Control (RBAC)** enforced via Firebase Security Rules:
  - **Customers** can only read their own allocation and transaction data.
  - **Shop Owners** can read/write only their assigned shop's inventory and queue.
  - **Authorities** have read access to all shops for monitoring and audit.
- Admin operations require authenticated sessions.

### 🗄️ Data Protection
- Firebase API keys used in the web portals are **restricted to authorized domains** only.
- Sensitive configuration files (`firebase-config.js`, `.env`) are excluded from version control via `.gitignore`.
- No hardcoded secrets exist in the production codebase.

### 🔒 Firmware Security
- ESP32 firmware uses `WiFiManager` for secure credential provisioning (no hardcoded WiFi passwords).
- Firebase REST API calls from the microcontroller include authentication tokens.
- Offline transaction caching is encrypted before sync.

## Reporting a Vulnerability

If you discover a security vulnerability in Smart PDS, please report it responsibly:

1. **Email:** Contact the maintainer at [vaishak.karkera@example.com] with:
   - A description of the vulnerability
   - Steps to reproduce
   - Potential impact assessment
   - Suggested fix (if any)

2. **Response Timeline:**
   - **Acknowledgment:** Within 48 hours
   - **Initial Assessment:** Within 1 week
   - **Fix & Disclosure:** Within 30 days for critical issues

3. **Do NOT:**
   - Open a public GitHub issue for security vulnerabilities.
   - Exploit the vulnerability beyond what is necessary to demonstrate it.
   - Share details publicly before a fix is released.

## Security Best Practices for Contributors

- Never commit API keys, tokens, or credentials to the repository.
- Always use environment variables or gitignored config files for secrets.
- Validate and sanitize all user inputs in web portals.
- Follow the principle of least privilege when modifying Firebase Security Rules.
- Test for XSS and injection vulnerabilities when modifying portal HTML/JS.

## Acknowledgments

We appreciate security researchers who help keep Smart PDS safe. Responsible disclosures will be credited in our release notes (with permission).
