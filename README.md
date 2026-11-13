# ![Ext icon](DarkEdif/irrKlang/Icon.png "Icon") irrKlang object

**irrKlang object** (Windows) is an audio extension for Clickteam Fusion 2.5 which acts as a wrapper around the [irrKlang](https://www.ambiera.com/irrklang/) C++/C# audio library. It wraps almost every feature that irrKlang offers into a Fusion extension.

The release is based off the free edition of irrKlang. As such, this extension must not be used for commercial purposes unless you have an irrklang Pro license & recompile this extension with the irrKlang Pro distribution.

## How to use the extension

[Download the latest release](https://github.com/nasiratif/irrKlang-object/releases) and unzip it to Fusion's root folder. Afterwards, in Fusion, click *Refresh* in the *Create new object* window to see the extension.

For more details, please see the extension's bundled HTML help file in the *About* section of the extension properties.

## How to build the source code

The extension source code resides in **DarkEdif/irrKlang**. It is based on a modified variant of the [DarkEdif SDK](https://github.com/SortaCore/MMF2Exts). Build the solution with Visual Studio 2019 & make sure you have the *Desktop development with C++* feature set installed.

What you'll specifically need, most importantly, is the *Windows SDK* (v7.1a) and the *v141_xp* toolset.

Please note that this extension can only be compiled under the Unicode build configurations.

**Unfortunately, as of writing, Ambiera has decided to take down the license to irrKlang Pro and even the download links to the free irrKlang library distribution. Since their license does not permit redistribution, I cannot include it in this repo. This extension can only be compiled if you already have the irrKlang includes/libraries on hand, which is one of the reasons I don't actively maintain nor recommend the use of this extension anymore.**