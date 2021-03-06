# 6Shots
WIP Multiplayer & singleplayer platformer twitch shooter. There isn't much gameplay at the moment, but multiplayer 'quickdraw' gamemode is functional.

Includes a map editor, inbuilt server hosting with a lobby, simulated physics.

# Controls
- W to jump / move up ladders
- A / D to move left and right
- Move the mouse to aim and move your hand
- Click when your hand is over a weapon to pick it up 
- Click with a weapon in your hand to shooter
- Right click to drop a weapon. You can throw it if you time it right!
----
- In singleplayer mode, press shift to test the gore effect

## Asset Sources:
### Images:
  - Tileset is from https://www.gameart2d.com/free-graveyard-platformer-tileset.html and is under CC0 licence
  - Other images are (badly) drawn by me
### Sound
  - Firearms sounds are from The Free Firearm Sound Library, and are under CC0 licence. (website now defunct, but details & licence info can be found [here](https://www.kickstarter.com/projects/bjjaszcz/the-firearm-sound-library/description)
### Font
  - Font used is Deja Vu Sans ( https://dejavu-fonts.github.io/ ), [used under the Bitstream Vera Fonts Licence](https://dejavu-fonts.github.io/License.html). Licence is built into the font.
  
# Dev Dependencies
- [Box2D](http://www.box2d.org) 
- [LUA v5.3](https://www.lua.org/)
- [SFML ^2.3.2](https://www.sfml-dev.org/download.php)
- [TGUI for SFML + example widgetset](https://tgui.eu/)
- [boost](https://www.boost.org/)
- [rapidxml](http://rapidxml.sourceforge.net/)

Also requires Visual Studio 2012 for now

# Building / Running
- Open the .sln in VS2012
- Download the above dependencies

# Screenshots
![Map Editor](EditMap.png "The Map Editor")

![Lobby](ServerScreenshot.png "Hosting / Joining a Multiplayer Server")

![Singleplayer](Screenshot-Gore-Effect.png "Singleplayer mode, with weapons weapons")
