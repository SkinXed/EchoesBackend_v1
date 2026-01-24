# Pilot Dashboard UI Mockup

## Visual Design Description

### Color Scheme
- **Primary**: #d4af37 (Imperial Gold)
- **Background**: Linear gradient from #0a0a0a to #1a1520
- **Text**: Gold shades (#d4af37, #b8962d, #8a7b3a)
- **Status Good**: #00ff00 (Green)
- **Error**: #ff6b6b, #8b0000 (Red shades)

## Loading State

```
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║                    ┌─────────────┐                       ║
║                    │             │                       ║
║                    │   ◯ ◉ ◯    │  ← Pulsing ring      ║
║                    │             │     (gold, animated)  ║
║                    └─────────────┘                       ║
║                                                           ║
║              SCANNING NEURAL LINK...                     ║
║              (blinking animation)                        ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝
```

## Main HUD Display

```
╔═══════════════════════════════════════════════════════════════════╗
║  ┌─────────────────────────────────────────────────────────────┐ ║
║  │                        HUD HEADER                           │ ║
║  ├──────────────────────────────┬──────────────────────────────┤ ║
║  │  COMMANDER SHEPARD           │                    CREDITS   │ ║
║  │  Freelancer                  │                   1,000,000  │ ║
║  │  (large gold text)           │           (monospace, gold)  │ ║
║  └──────────────────────────────┴──────────────────────────────┘ ║
║                                                                   ║
║  ┌─────────────────────────────────────────────────────────────┐ ║
║  │                        HUD BODY                             │ ║
║  ├──────────────────────────────┬──────────────────────────────┤ ║
║  │  CURRENT LOCATION            │  ACTIVE SHIP                 │ ║
║  │  ┌────────────────────────┐  │  ┌────────────────────────┐ │ ║
║  │  │                        │  │  │                        │ │ ║
║  │  │  JITA                  │  │  │  IMPERIAL FRIGATE      │ │ ║
║  │  │  (large gold text)     │  │  │  (large gold text)     │ │ ║
║  │  │                        │  │  │                        │ │ ║
║  │  └────────────────────────┘  │  └────────────────────────┘ │ ║
║  └──────────────────────────────┴──────────────────────────────┘ ║
║                                                                   ║
║  ┌─────────────────────────────────────────────────────────────┐ ║
║  │                       HUD FOOTER                            │ ║
║  │                                                             │ ║
║  │              ● NEURAL LINK STABLE                          │ ║
║  │           (green pulsing dot)                              │ ║
║  └─────────────────────────────────────────────────────────────┘ ║
╚═══════════════════════════════════════════════════════════════════╝
```

## Error State

```
╔═══════════════════════════════════════════════════════════╗
║                                                           ║
║                         ⚠️                                ║
║                                                           ║
║              Session expired. Please login again.        ║
║                                                           ║
║                 ┌───────────────────┐                    ║
║                 │  RETRY CONNECTION │                    ║
║                 └───────────────────┘                    ║
║                  (red glowing button)                    ║
║                                                           ║
╚═══════════════════════════════════════════════════════════╝
```

## CSS Effects

### 1. Pulse Ring Animation
- Scale from 1.0 to 1.1 and back
- Opacity fades from 1.0 to 0.6
- Duration: 2 seconds
- Easing: ease-in-out
- Loop: infinite

### 2. Text Blink Animation
- Opacity alternates between 1.0 and 0.3
- Duration: 1.5 seconds
- Timing: step-start (instant transition)
- Loop: infinite

### 3. Status Dot Pulse
- Opacity fades from 1.0 to 0.5 and back
- Duration: 2 seconds
- Easing: ease-in-out
- Loop: infinite
- Box shadow glow effect

### 4. HUD Fade In
- Starts at opacity 0, translateY(-20px)
- Ends at opacity 1, translateY(0)
- Duration: 0.5 seconds
- Easing: ease-in

### 5. Button Hover Effects
- Background gradient shift
- Box shadow glow intensifies
- Transform: translateY(-2px)
- Transition duration: 0.3s
- Easing: ease

## Layout Grid Specifications

### Desktop Layout (> 768px)
- Header: 2 columns (50% / 50%)
- Body: 2 columns (50% / 50%)
- Footer: 1 column (centered)

### Mobile Layout (≤ 768px)
- Header: 1 column (stacked)
- Body: 1 column (stacked)
- Footer: 1 column (centered)

## Typography

### Pilot Name
- Font size: 2.5rem
- Font weight: bold
- Color: #d4af37
- Text transform: uppercase
- Letter spacing: 0.1rem
- Text shadow: 0 0 10px rgba(212, 175, 55, 0.5)

### Corporation Name
- Font size: 1.2rem
- Color: #b8962d
- Text transform: uppercase
- Letter spacing: 0.05rem

### Credits Value
- Font size: 2.5rem
- Font family: 'Courier New', monospace
- Color: #d4af37
- Font weight: bold
- Text shadow: 0 0 10px rgba(212, 175, 55, 0.5)

### Panel Values
- Font size: 1.8rem
- Color: #d4af37
- Font weight: bold
- Text transform: uppercase

## Interactive Elements

### Retry Button
- Background: Linear gradient (red shades)
- Border: 1px solid #ff0000
- Padding: 1rem 2rem
- Border radius: 4px
- Cursor: pointer
- Letter spacing: 0.1rem
- Hover effect: Glow and lift

## Accessibility Features

1. **Semantic HTML**: Proper heading hierarchy
2. **ARIA labels**: For interactive elements
3. **Keyboard navigation**: All buttons are keyboard accessible
4. **Color contrast**: Meets WCAG AA standards
5. **Responsive**: Works on all screen sizes

## Browser Compatibility

- Chrome/Edge: Full support
- Firefox: Full support
- Safari: Full support
- Mobile browsers: Full support

## Performance Optimizations

1. **CSS animations**: Hardware accelerated (transform, opacity)
2. **Minimal repaints**: Fixed layouts
3. **Efficient selectors**: Class-based
4. **Lazy loading**: Data fetched only when needed
