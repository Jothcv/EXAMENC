JONATHAN@Papu MINGW64 ~ (4.spring-security-jwt)
$ cd ..

JONATHAN@Papu MINGW64 /c/Users
$ cd JONATHAN

JONATHAN@Papu MINGW64 ~ (4.spring-security-jwt)
$ cd desktop

JONATHAN@Papu MINGW64 ~/desktop (Equipo3)
$ mkdir EXAMENC

JONATHAN@Papu MINGW64 ~/desktop (Equipo3)
$ cd EXAMENC

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git init
Initialized empty Git repository in C:/Users/JONATHAN/Desktop/EXAMENC/.git/

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (master)
$ touch .gitignore

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (master)
$ code .

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (master)
$ git add .gitignore

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (master)
$ git commit -m "se creo la carpeta del exmaen y se agrego el archivo .gitignore
> "
[master (root-commit) 434405e] se creo la carpeta del exmaen y se agrego el archivo .gitignore
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 .gitignore

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (master)
$ git branch -M main

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git branch
* main

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git branch Equipo1

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git branch Equipo2

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git branch Equipo3

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ touch HistorialGit

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ touch ManualPrograma1.md

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ touch ManualPrograma2.md

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ touch ManualPrograma3.md

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git add .

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git commit -m "se agregaron los manuales de cada sistema a la rama main"
[main 8e2674c] se agregaron los manuales de cada sistema a la rama main
 4 files changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 HistorialGit.md
 create mode 100644 ManualPrograma1.md
 create mode 100644 ManualPrograma2.md
 create mode 100644 ManualPrograma3.md

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git switch Equipo1
Switched to branch 'Equipo1'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ touch Programa1

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git switch main
Switched to branch 'main'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git switch Equipo2
Switched to branch 'Equipo2'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git switch Equipo1
Switched to branch 'Equipo1'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git add Programa1.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git commit -m "se agrego el primer programa del Equipo1"
[Equipo1 6cad6b7] se agrego el primer programa del Equipo1
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Programa1.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git switch Equipo2
Switched to branch 'Equipo2'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ touch Programa2.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git add Program2.c
fatal: pathspec 'Program2.c' did not match any files

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git add Programa2.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git commit -m "se agrego el primer programa del equipo2"
[Equipo2 f214f2f] se agrego el primer programa del equipo2
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Programa2.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git switch Equipo3
Switched to branch 'Equipo3'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git touch Programa3.c
git: 'touch' is not a git command. See 'git --help'.

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ touch Programa3.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git add Programa3.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git commit -m "se agrego el primer porgrama del equipo3"
[Equipo3 c4e5135] se agrego el primer porgrama del equipo3
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Programa3.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git switch main
Switched to branch 'main'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git add .

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git commit -m "se puso un concepto de los manuales"
[main 884263c] se puso un concepto de los manuales
 3 files changed, 553 insertions(+)

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git switch Equipo1
Switched to branch 'Equipo1'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git add Programa1.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git commit -m "se finalizo el primero porgrama del Equipo1"
[Equipo1 52bdd44] se finalizo el primero porgrama del Equipo1
 1 file changed, 126 insertions(+)

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo1)
$ git switch Equipo2
Switched to branch 'Equipo2'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git add Programa2.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git commit -m "se agrego el primer programa del equipo2"
[Equipo2 ffeaf75] se agrego el primer programa del equipo2
 1 file changed, 157 insertions(+)

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo2)
$ git switch Equipo3
Switched to branch 'Equipo3'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git add Programa3.c

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git commit -m "se el primer programa del Equipo3"
On branch Equipo3
nothing to commit, working tree clean

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git log
commit c4e513589fee9e999285abc3b49862287b9e3d75 (HEAD -> Equipo3)
Author: Jothcv <soulkry.0@gmail.com>
Date:   Tue Aug 13 18:01:54 2024 -0600

    se agrego el primer porgrama del equipo3

commit 434405e7a9d83424c183208ff29479da60a6fe46
Author: Jothcv <soulkry.0@gmail.com>
Date:   Tue Aug 13 17:53:50 2024 -0600

    se creo la carpeta del exmaen y se agrego el archivo .gitignore

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git switch main
error: Your local changes to the following files would be overwritten by checkout:
        Programa3.c
Please commit your changes or stash them before you switch branches.
Aborting

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git add .

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git commit -m "se agrego el tercer bueno el primero programa del Equipo3"
[Equipo3 395945f] se agrego el tercer bueno el primero programa del Equipo3
 1 file changed, 73 insertions(+)

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (Equipo3)
$ git switch main
Switched to branch 'main'

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git merge Equipo1

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git merge Equipo2

JONATHAN@Papu MINGW64 ~/desktop/EXAMENC (main)
$ git merge Equipo3