# Getting Started Guides

This directory contains guides to help you get started with Echoes development.

---

## 📚 Available Guides

- **[Quick Start Guide](QUICK_START_GUIDE.md)** - Get up and running quickly with the Echoes client

---

## 🚀 Quick Links

### For New Developers

1. **[Quick Start Guide](QUICK_START_GUIDE.md)** - Set up your development environment
2. **[Architecture Overview](../architecture/README.md)** - Understand the codebase structure
3. **[Inventory System](../systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)** - Study a complete system

### For Backend Developers

If you're familiar with the backend API and want to work on the UE5 client:

1. Read [Architecture Overview](../architecture/README.md) to understand the mirror architecture
2. Review [Network Security](../architecture/NETWORK_SECURITY.md) for API communication
3. Study a subsystem like `UEchoesAuthSubsystem` to see HTTP integration

### For UE5 Developers

If you're experienced with Unreal Engine but new to this project:

1. Read [Quick Start Guide](QUICK_START_GUIDE.md) for project setup
2. Review the [code organization](../architecture/README.md#code-organization)
3. Understand the [function naming convention](../architecture/README.md#function-naming-convention)
4. Study [Inventory Component](../systems/INVENTORY_COMPONENT_IMPLEMENTATION.md) as an example

---

## 🎯 Common Tasks

### Running the Client

1. Start backend API (from main repository)
2. Open `Echoes.uproject` in Unreal Editor
3. Press `Alt+P` to Play in Editor

### Making Your First Change

1. Find the relevant subsystem or component
2. Add your functionality following naming conventions
3. Test in PIE (Play in Editor)
4. Submit a pull request

### Adding a New Feature

1. **Backend First**: Create API endpoint in C# backend
2. **Subsystem**: Add HTTP call to relevant subsystem
3. **Component**: Implement game logic in component
4. **UI**: Create widget for user interaction
5. **Documentation**: Update relevant docs

---

## 🔧 Development Tools

### Required Tools

- Unreal Engine 5.6+
- Visual Studio 2022 (with C++ workload)
- Git

### Recommended Tools

- Visual Assist (C++ IntelliSense)
- Unreal Insights (profiling)
- RenderDoc (graphics debugging)
- Postman (API testing)

---

## 📖 Learning Resources

### Unreal Engine

- [Official UE5 Documentation](https://docs.unrealengine.com/5.6/)
- [UE5 C++ API Reference](https://docs.unrealengine.com/5.6/en-US/API/)
- [UE5 Networking Guide](https://docs.unrealengine.com/5.6/en-US/networking-and-multiplayer-in-unreal-engine/)

### Project-Specific

- [Main README](../../README.md) - Project overview
- [Documentation Index](../README.md) - All documentation
- [Backend Repository](https://github.com/SkinXed/EchoesBackend_v1) - Backend API

---

## 🆘 Getting Help

### Documentation

- Check [Documentation Index](../README.md) for specific topics
- Search existing documentation for keywords
- Review code examples in components

### Issues

- Search GitHub issues for similar problems
- Create new issue with detailed description
- Include logs and steps to reproduce

### Code Examples

The best way to learn is by example:

- **Inventory System** - [Complete System](../systems/COMPLETE_INVENTORY_SYSTEM_SUMMARY.md)
- **HTTP API Calls** - See `UEchoesAuthSubsystem.cpp`
- **UI Widgets** - See `UEchoesInventoryWidget.cpp`
- **Components** - See `UEchoesInventoryComponent.cpp`

---

**Last Updated**: 2026-02-01
