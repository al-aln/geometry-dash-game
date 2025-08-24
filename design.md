
# Geometry Dash Clone - Design Document

## 1. Introduction

*   **Game Title (C-dash):**
*   **Genre:** Rhythm-Based Platformer
*   **Platform:** Initially PC (Windows and Linux)
*   **Target Audience:** myself
*   **Game Overview:** A fast-paced, rhythm-based platformer where the player controls a block-like character and must navigate increasingly challenging levels synchronized to music.

## 2. Gameplay Mechanics

*   **Core Mechanic:** The player must jump and avoid obstacles
*   **Controls:**
    *   **Jump:** Spacebar/Up Arrow
    *   **Menu Navigation:** Mouse
*   **Level Progression:** Players progress linearly through levels. Difficulty increases with each level.
*   **Difficulty:** Defined by speed of obstacles and the overall tightness of the timing windows.
*   **Death:** One hit death. Restart the level from the beginning.
*   **Scoring:** (Optional – consider adding a simple score based on level completion time/perfect hits)
*   **Rhythm Synchronization:** Gameplay events (obstacles appearing, triggers activating, music cues) are tightly linked to the music's beat. This is *essential* for the game's feel.

**Technical Considerations:**

*   **Raylib Audio:** Crucial for accurate music playback and synchronization. Look into Raylib's audio mixer and potential for precise timing.
*   **Game Loop Synchronization:** The game loop must be synchronized with the music's tempo.

## 3. Game Features

*   **Side Scrolling Screen:** The camera follows the player horizontally.
*   **Levels:**
    *   Multiple levels increasing in difficulty.
*   **Skins:**
    *   Cosmetic changes to the player’s appearance.
    *   Acquired through gameplay or in-game currency.
*   **Music:**
    *   A variety of music tracks for different levels. Different genres/styles.
    *   Music volume adjustable in options.
*   **In-Game Currency:**
    *   Earned by completing levels, achieving milestones, or through achievements.
    *   Used to purchase skins and unlock level.
*   **Achievements:** Tracked and displayed to the player.
*   **Parallax Scrolling:** Background layers move at different speeds

**Technical Considerations:**

*   **Parallax Layers:** Implement multiple background layers, each moving at a different speed.
*   **UI Rendering:** clear and visually appealing user interface for the main menu, level selection, and in-game displays.
*   **Data Persistence:** system that saves and loads player progress
*   **UI State Management:** Manage different UI states and handle user input appropriately.

## 4. User Interface (UI)

*   **Main Menu:**
    *   Start Game Button
    *   Level Selection Button
    *   Skins Button
    *   Options Button
    *   Achievements Button
*   **Level Selection Screen:** Displays available levels with unlock status.
*   **Options Screen:** Volume control, Graphics settings
*   **In-Game UI:** Simple display of current level. Potential for a timer.
*   **Pause Screen:** Allows the player to resume, restart, or return to the main menu.

## 5. Art Style & Visuals

*   **Style:** Pixel Art, Clean and Minimalist.
*   **Color Palette:** Bright and contrasting colors.
*   **Animations:** Smooth and responsive character and obstacle animations.
*   **Visual Feedback:** Visual cues to indicate the beat 

**Technical Considerations:**

*   **Raylib Renderer:** Use Raylib’s rendering capabilities to create the visual elements.
*   **Sprite Management:** Efficiently manage and render sprites for the player, obstacles, and background.
*   **Animation Frames:** Create animation frames for the player and obstacles.

## 6. Sound Design

*   **Music:** Upbeat and rhythmic music tracks.
*   **Sound Effects:** Distinct sounds for jumping, dying, collecting currency, and other events.
*   **Sound Mixing:** Properly mix music and sound effects to create a balanced and immersive audio experience.

**Technical Considerations:**

*   **Raylib Audio:** Use Raylib’s audio mixer to manage sound effects and music.
*   **Sound Effects Libraries:** sound effects library for integrating sound effects.

## 7. Progression and Unlockables

*   **Levels:** Unlock new levels by completing previous ones.
*   **Skins:**
    *   Purchase with in-game currency.
    *   Unlock by completing specific levels

## 8. Technical Details

*   **Programming Language:** C++
*   **Graphics Library:** Raylib
*   **Build System:** (CMake, Make, etc.)
*   **Version Control:** Git
*   **File Format for Levels/Data:** JSON

## 9. Extra

*   **More Complex Obstacles/Mechanics:** new gameplay elements beyond jumps
*   Level editor functionality (Optional - for future expansion. Complex to implement).

**Important Notes:**

*   **Scope Management:** Start small and focus on the core gameplay loop. Add features incrementally.
*   **Iteration:** Regularly playtest the game and iterate on the design based on feedback.
*   **Music Synchronization:** The most significant technical challenge is synchronizing gameplay events with the music. Prioritize this from the beginning.
