# Duel Rank Calculator
**For Yu-Gi-Oh! Forbidden Memories**

## About this software
This is almost an exact clone of the older, no longer maintained rank calculator by Flurputzer, which you can find on the [speedrun.com resources page](https://www.speedrun.com/yugiohfm/resources) as part of a pack of generally useful Forbidden Memories Tools. The old calculator contained some errors which have been fixed in this version. The information used to create this calculator is derived from [this forum post](https://www.neoseeker.com/forums/3085/t2018541-calculating-duel-rank/) and has been cross-checked against ingame memory values.

The purpose of this software is for it to be used while playing Yu-Gi-Oh! Forbidden Memories for the PS1 to keep track of your current duel rank. This is useful due to the fact that certain cards can only be obtained by achieving a specific duel rank, and doing so can sometimes require a very specific set of actions to be performed.

The most important duel rank in the game is the S/A-tec rank, which requires the player to keep track of actions such as fusions, life points lost, traps activated and more in order to achieve. Obtaining an S/A-tec rank on certain opponents may grant the player access to some of the strongest winnable cards in the game, such as Megamorph.

![Screenshot of main software interface](https://user-images.githubusercontent.com/17675149/222932178-1859eac5-1818-4d23-885a-7b016841431d.png)

This rank calculator boasts an easy-to-use user interface which allows you to add and subtract from the various actions which are possible during a duel in Yu-Gi-Oh! Forbidden Memories. A display near the bottom of the program interface lets the user know, based on the actions performed, what the duel rank would be if the duel ended at that moment.

When attempting to obtain certain duel ranks, such as an A-tec, it is often the case that some duel actions are performed a consistent number of times, or are counted easily in-game and do not need to be continuously checked off by the player within this calculator. By checking the box next to any individual action, the number will not be reset when the reset button is pressed. Clicking the "A-tec mode" button will set life points, turns, and cards used to the amount required for the most common A-tec methods.

![Screenshot of hotkey-rebinding interface](https://user-images.githubusercontent.com/17675149/222932331-2b744742-553d-4933-b777-f915612c2564.png)

Each duel action may also be quickly kept track of using rebindable hotkeys which can be saved and loaded. Please note that on Windows the file corresponding to the saved hotkey configuration is stored in `%APPDATA%/hippochan/FMRankCalc.ini`.
  
## Building from source
This program was created in C++ using Qt VS Tools and the downloadable binaries were compiled for Windows using `windeployqt` to fetch the required Qt dynamic link libraries. Included in the source download under `FMRankCalc/` are the `.pro` and `.pri` files required for cross-platform deployment, however, these have not yet been tested. You should make sure that you have Qt and a C++ build system such as `cmake` installed, then run `qmake` and `make`.
