# Changelog

All notable changes to the Smart PDS project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

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
