sourceanalyzer.exe -b mybuild -clean
sourceanalyzer -b mybuild devenv  ConsoleApplication1.sln  /REBUILD
sourceanalyzer.exe -b mybuild -scan -f 2.fpr -verbose