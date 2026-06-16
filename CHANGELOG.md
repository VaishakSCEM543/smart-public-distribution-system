# Changelog

All notable changes to the Smart PDS project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [v3.6.0] — 2026-06-17

### Added
- **`scale.cpp`:** `isWithinTolerance(dispensed, target)` — returns true if weight deviation is within the 5g acceptance window.
- **`scale.cpp`:** `retare()` — re-zeros the load cell between sessions; useful after each successful dispense.
- **`scale.cpp`:** `WEIGHT_ZERO_THRESHOLD` constant (2g) — clamps near-zero noisy readings to exactly 0.
- **`display.cpp`:** `showError(msg)` — displays a prominent `"! ERROR !"` header on the LCD with the message on line 2.
- **`display.cpp`:** `showStatus(msg)` — single-line status update helper for brief system state messages.
- **`auth.cpp`:** OTP expiry timer — OTPs are now invalidated after 2 minutes automatically.
- **`auth.cpp`:** 3-attempt lockout — after 3 incorrect OTP entries the session is locked.
- **`auth.cpp`:** `AuthResult` enum — `AUTH_OK`, `AUTH_WRONG`, `AUTH_EXPIRED`, `AUTH_LOCKED` for structured error handling.
- **`auth.cpp`:** `resetAuth()` — clears all OTP state after a session ends.
- **`hardware/components-list.md`:** Full ESP32 GPIO wiring table for all components (HX711, servo, LCD, keypad, IR sensor) with power supply notes.
- **`docs/system-architecture.md`:** Full architecture document with layer tables, firmware module breakdown, and end-to-end data flow diagram.
- **`docs/workflow.md`:** Detailed 6-step dispensing workflow with firmware pseudocode, Firebase payload example, and error handling table.
- **`docs/feasibility-and-impact.md`:** Complete feasibility study with component cost table, national ROI analysis, social impact breakdown, scalability plan, and risk mitigation table.

### Fixed
- **`wifi_manager.cpp`:** Replaced infinite `while(WiFi.status() != WL_CONNECTED)` loop with a bounded retry counter (20 attempts × 500ms). Prevents ESP32 hanging forever if the network is unavailable.
- **`firebase.cpp`:** `sendToFirebase()` now returns `bool` instead of `void`. Added HTTP status code interpretation (401 Unauthorized, 400 Bad Request, network errors) and a WiFi connectivity guard before every request.
- **`display.cpp`:** Added 16-character line clamping via `substring(0, 16)` to prevent LCD overflow and display corruption on long strings.

### Changed
- **`esp32.ino`:** Main loop now uses `showError()` on Firebase upload failure, `isWithinTolerance()` to detect dispense completion, and `retare()` after a successful session. Magic numbers replaced with named constants (`SYNC_INTERVAL_MS`, `DISPENSE_TARGET_G`).
- **`scale.cpp`:** `readWeight()` now averages `WEIGHT_SAMPLES` (10) readings and applies zero-threshold clamping before returning.

---

## [v3.5.0] — 2026-05-08

### Added
- Premium SaaS redesign for Shop Owner Portal with sidebar navigation and live interactive simulations.
- Modernized Customer Portal with pill-button category selection and upgraded feedback UI.
- Enhanced login inputs with premium glassmorphism styling across all portals.

### Fixed
- Token text wrapping issue on both Shop Owner and Customer portals for long token strings.
- Category toggle behavior in Customer Portal ensuring proper state management.
- Firebase queue real-time logic properly integrated into the new Shop Owner redesign.

### Changed
- Neon counter in Shop Owner Portal replaced with sleek modern SaaS design supporting long tokens.
- Overall portal UI overhaul to premium, production-ready aesthetics.

---

## [v3.0.0] — 2026-05-07

### Added
- **AI Fraud Analyst:** Integrated Grok AI chatbot in Authority Portal for live data analysis and risk assessment reports.
- **Dynamic Analytics:** Live charts and visual representations using Chart.js for stock distribution and anomaly detection.
- **AI Demo Mode:** Smart fallback for the public GitHub Pages deployment when Firebase is unavailable.
- **GitHub Pages Landing Page:** Premium landing page (`index.html`) with portal navigation.
- **CSV Export:** Proper filenames and Excel-compatible CSV downloads for audit reports.

### Changed
- Authority Portal login upgraded to premium glassmorphism design.
- All static/hardcoded data eliminated from Authority Portal — fully dynamic Firebase-driven UI.
- README overhauled with cyber-physical architecture diagram (Mermaid) and live demo links.

### Security
- Removed all hardcoded API keys from production codebase.
- Firebase configuration moved to gitignored config files.

---

## [v2.0.0] — 2026-02-23

### Added
- Professional firmware documentation for ESP32 codebase.
- System architecture diagram embedded in README.
- Prototype photos and hardware demonstration video.
- Comprehensive project documentation:
  - Problem statement
  - System architecture
  - Workflow documentation
  - Feasibility and impact analysis
  - Future scope roadmap

### Changed
- README formatting improvements and structural updates.

---

## [v1.0.0] — 2026-02-23

### Added
- Initial release of Smart PDS.
- ESP32 firmware with WiFi connectivity, load cell integration, and Firebase sync.
- Three web portals: Authority, Customer, Shop Owner.
- Firebase Realtime Database integration.
- Basic transaction logging and inventory management.
- Hardware component documentation.
- MIT License.
