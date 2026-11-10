ac3f3f9dd5d54e9fc2c980b33450c79f23ad58b2	HEAD -> master
Fork: https://github.com/SortaCore/MMF2Exts/ (unconfirmed)

To keep this file edited without Git requesting you upgrade it, you can add to local-only gitignore, by appending "DarkEdif/Lib/GitArchiveCommit.md" to your ".git/info/exclude" file.

Last commit before archive was at 2026-10-08T00:24:29+01:00
Downloaded with tree hash: e0e01a2e262d1cdcf69a60d605bdfb996202d6fe
DarkEdif: Fix OS version lookup

RtlGetVersion isn't ANSI style.


With any refs being:




In git clones/forks, the lines above remain unaffected, remaining format strings.
This is arranged by .gitattributes export-subst and read by FusionSDK.props for SDK update checks.

In git archive/zip exports, the above line becomes a full SHA and branch, like:
1. fullshahash HEAD -> master  
   Zip download of the tip of master branch.
2. fullshahash secondbranch  
   Zip download of tip of a different remote branch.
3. fullshahash  
   Zip download when cloning the non-tip of any remote branch.

Note forks are not detectable with the method, leading to build-time edits to this file above.
If the fork line is still unconfirmed above, these edits have not happened.
