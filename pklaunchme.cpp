// pklaunchMe.cpp - launches PEAKFQ after copying into the current
// directory the files that are required during execution and making
// available a minimum subset of environment variables, avoiding the
// memory protection fault that could otherwise occur in running a
// purely DOS application under 32-bit Windows OSes in the presence
// of environment variables with values longer than 255 characters.

// Executes ansi.com (public-domain replacement for ansi.sys) before
// launching executable.  ansi.com must be used instead of ansi.sys on
// Windows Me systems where ansi.sys (and other DOS real-mode device
// drivers) can't be loaded without booting Windows Me from a modified
// Startup Disk.

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>

void main()
{
        char msgFile[] = "pkfqms.wdm";
        char app[] = "peakfql.exe";
        // Note that MAX_PATH is a constant defined in stdlib.h. It is
        // the maximum number of characters in a path name.
        char home[MAX_PATH], shorthome[MAX_PATH], cmd[MAX_PATH];
        char *args[2], *env[5];
        char comspec[255], systemRoot[255], temp[255], tmp[255];
        int pathLen;

        // Retrieve the full path name of this "launcher" program, for 
        // example, D:\USGS\AppName\bin\launcher.exe. It is assumed that
        // the launcher is placed in the same folder as the Fortran 
        // executable to be launched.
        GetModuleFileName(NULL, home, MAX_PATH);

        // Search for the last file separator (backslash) and replace it
        // with a null character. Do this twice. This yields the "home" 
        // directory. For example, D:\USGS\AppName
        *(strrchr(home, '\\')) = '\0';
        *(strrchr(home, '\\')) = '\0';

        // Copy files to the current working directory. This is done by 
        // putting the command into the character array "cmd", and then 
        // executing the command using the "system" function.
        sprintf(cmd, "copy \"%s\\bin_data\\lf90.eer\"", home);
        system(cmd);
        sprintf(cmd, "copy \"%s\\bin_data\\%s\"", home, msgFile);
        system(cmd);
        sprintf(cmd, "copy \"%s\\bin_data\\*.chr\" > nul", home);
        system(cmd);
        // Test the existence of interact.ini by trying to open it.
        FILE *stream = fopen("interact.ini", "r");
        if (stream == NULL)
        {
                // If interact.ini doesn't exist, then copy it to the 
                // working directory
                sprintf(cmd, "copy \"%s\\bin_data\\interact.ini\"", home);
                system(cmd);
        }
        else
        {
                // If interact.ini opens, then just close it.
                fclose(stream);
        }

        // Create the environment variables to be passed to the process
        // that is spawned below. The process will only "know" these
        // environment variables and not any other ones defined in
        // the system. The minimum required environment variables are:
        // comspec    - the full path name of the active command shell
        // SystemRoot - the Windows directory under NT/2000, used to
        //              find %SystemRoot%\system32\config.nt in order 
        //              to set up the DOS command window. Under Windows 
        //              9x, getenv("SystemRoot") returns NULL.
        // temp, tmp  - the directory for temporary files
        sprintf(comspec, "comspec=%s", getenv("comspec"));
        sprintf(systemRoot, "SystemRoot=%s", getenv("SystemRoot"));
        sprintf(temp, "temp=%s", getenv("TEMP"));
        sprintf(tmp, "tmp=%s", getenv("TMP"));
        env[0] = comspec;
        env[1] = systemRoot;
        env[2] = temp;
        env[3] = tmp;
        env[4] = NULL;

        // get short path name for "home" directory
        pathLen = GetShortPathName(home, shorthome, MAX_PATH);
        if (pathLen == 0) {
                printf ("Warning: couldn\'t get short path for executable "
                        "(error code=%d);\n         will use original path...\n", 
                        GetLastError());
                strcpy(shorthome, home);
        }

        // execute ansi.com w/ screen writes via BIOS ("slow") in quiet mode 
        sprintf(cmd, "%s\\bin\\ansi.com slow /q", shorthome);
        system(cmd);

        // construct the path of the executable to be launched
        sprintf(cmd, "%s\\bin\\%s", shorthome, app);
        args[0] = cmd;
        args[1] = NULL;

        // Spawn the process. This launcher will wait until the 
        // spawned process is terminated before continuing.
        printf ("executing %s\n", args[0]);
        _spawnvpe(_P_WAIT, args[0], args, env);

        // Delete files in the working directory
        sprintf(cmd, "del lf90.eer");
        system(cmd);
        sprintf(cmd, "del %s", msgFile);
        system(cmd);
        sprintf(cmd, "del *.chr");
        system(cmd);
}
