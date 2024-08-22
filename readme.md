# Custom Macropad with QMK and VIAL Support
![test](https://github.com/user-attachments/assets/7e281194-e074-43e5-a750-de7b1ccfd4a5)

<img src="https://github.com/favicon.ico" height="80">

## This project is for anyone starting with QMK, providing examples that can be used in their own code, as setting up this project was quite challenging.

This arcade project was possible with my cousin's board he gave to me of which he created from onboard.
It can perform the following actions:

- Rotary Encoder Support via GUI for media playback, video editing, cad, and more.
- OLED layer support.
- Custom macros that you can make in VIAL.
- Autoclicker script by Pascal Getreue.
- 72 Configurable Keys
- Easy GUI remapping


# Here are some Macros that I use:

- ALT+CTRL+SHIFT+F1: To open Discord via Window Shortcuts
- ALT+CTRL+SHIFT+F2: To open Spotify
- ALT+CTRL+SHIFT+F3: To mute in Discord

Since Arc(my browser) doesn't have support for shortcuts I use the following:
`WIN+R` Type in `arc` delay 200ms `ENTER`

# This project is also built on top the my [fork of QMK](https://github.com/qmk/qmk_firmware/compare/master...Alecsis:qmk_firmware:master) <br />
I am sorry to whoever is reviewing this due to looking at two repos, VIAL is a fork of the default QMK firmware so that is why :(


# Reflection
This is my first major project, and through this journey, I implemented some ideas and features, such as animations, but dropped the idea when it came to practicality. It also shows new efficient techniques, such as when I used to program macros directly into QMK via the `WIN + R` code, which was hit or miss half of the time.

# Sourses / Attributions!

This whole project would not have happened if my cousin had not sent me the board! So thanks to him!

[QMK DOCS](https://docs.qmk.fm/)<br />
[VIAL PORTING](https://get.vial.today/docs/)<br />
[WINDOWS SHORTCUTS](https://www.youtube.com/watch?v=wkyzO7Mz2Ls)]<br />
W REDDIT POST WITH [BOOTLOADER INSTRUCTIONS](https://www.reddit.com/r/olkb/comments/9ctx37/qmk_burn_dfu_bootloader_into_keyboard_with/) <br />
HUGE THANKS TO THIS GUY THAT MADE THE [AUTOCLICKER SCRIPT](https://getreuer.info/posts/keyboards/mouse-turbo-click/index.html)<br />
[Image to CPP](https://javl.github.io/image2cpp/)<br />
[Joe Scotto's QMK OLED Documentation](https://www.youtube.com/watch?v=OJSOEStpPIo)<br />
[Joe Scotto's VIAL Porting Tutorial](https://www.youtube.com/watch?v=O8pdUPqPG3k)<br />
