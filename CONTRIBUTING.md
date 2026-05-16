# Contributing to Smart PDS

Thank you for your interest in contributing to the **Smart Public Distribution System**! This guide will help you get started.

## 🛠️ Development Setup

### Prerequisites

- A modern web browser (Chrome, Firefox, Edge)
- A text editor or IDE (VS Code recommended)
- Git installed on your system
- A Firebase account (for backend integration testing)

### Getting Started

1. **Fork the repository**
   ```bash
   git clone https://github.com/YOUR_USERNAME/smart-public-distribution-system.git
   cd smart-public-distribution-system
   ```

2. **Open the project** — Since the web portals are vanilla HTML/JS/CSS, you can open any `index.html` directly in your browser or use a local dev server:
   ```bash
   # Using Python
   python -m http.server 8080

   # Using Node.js
   npx serve .
   ```

3. **Firebase Configuration** — To connect to a Firebase backend, create a `firebase-config.js` file (this is gitignored for security):
   ```js
   const firebaseConfig = {
     apiKey: "YOUR_API_KEY",
     authDomain: "YOUR_PROJECT.firebaseapp.com",
     databaseURL: "https://YOUR_PROJECT-default-rtdb.firebaseio.com",
     projectId: "YOUR_PROJECT_ID",
     storageBucket: "YOUR_PROJECT.appspot.com",
     messagingSenderId: "YOUR_SENDER_ID",
     appId: "YOUR_APP_ID"
   };
   ```

## 📂 Project Structure

```
smart-public-distribution-system/
├── web/
│   ├── authority/    # Government admin dashboard
│   ├── customer/     # Beneficiary portal
│   └── shop-owner/   # FPS owner dashboard
├── firmware/         # ESP32 Arduino code
├── hardware/         # Component lists & schematics
├── docs/             # Documentation
├── demo/             # Screenshots & demo material
└── index.html        # GitHub Pages landing page
```

## 🔄 Workflow

1. Create a feature branch from `main`:
   ```bash
   git checkout -b feat/your-feature-name
   ```

2. Make your changes and test thoroughly.

3. Commit with [Conventional Commits](https://www.conventionalcommits.org/) format:
   ```bash
   git commit -m "feat(portal): add real-time notification system"
   git commit -m "fix(authority): resolve chart rendering on mobile"
   git commit -m "docs: update API reference with new endpoints"
   ```

4. Push to your fork and open a Pull Request.

## 🎨 Code Style Guidelines

### HTML / CSS / JavaScript

- Use **2-space indentation** for HTML, CSS, and JS files.
- Use **semantic HTML5** elements (`<header>`, `<main>`, `<section>`, etc.).
- Follow **BEM naming convention** for CSS classes where applicable.
- Prefer **CSS custom properties** (variables) for theming.
- Use **ES6+ features** (arrow functions, template literals, destructuring).
- All interactive elements must have **unique IDs** for accessibility and testing.

### Firmware (C++ / Arduino)

- Follow the existing code structure in `firmware/`.
- Comment all hardware pin definitions and calibration values.
- Test on real ESP32 hardware before submitting changes.

## 🧪 Testing

- **Web Portals:** Test across Chrome, Firefox, and Edge. Verify mobile responsiveness.
- **Firebase Integration:** Ensure real-time listeners work correctly and data schemas match documentation.
- **Firmware:** Test with serial monitor output before deployment.

## 📋 Issue Guidelines

When opening an issue, please include:

- **Bug reports:** Steps to reproduce, expected vs actual behavior, browser/device info, screenshots.
- **Feature requests:** Clear description, use case, and any mockups if applicable.

## 🤝 Code of Conduct

- Be respectful and constructive in discussions.
- Provide helpful, actionable feedback in code reviews.
- Focus on the problem, not the person.

## 📄 License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
