# Line follower code

This is a repository for line follower code. Instructions for 
hardware setup should be forthcoming as well. 

HOW TO UPLOAD CODE TO GITHUB

- clone the repository. this means typing in 
```
git clone git@github.com:ece-idc-2016/lineFollower.git
```
to your terminal. **only do this one time.**

- change directories to the repository you just cloned. this means typing 
```
cd lineFollower
```
in your terminal.

- make a branch for yourself so you don't mess up other people's code. make a new branch by typing in 
```
git branch *YOURNAME*
```
**Only do this ONE time!!!!** 

- switch to that branch with 
```
git checkout *YOURNAME*
```
**do this EVERY time!!**

- type in 
```
git pull
``` 
to make sure you have the current version. **do this every time!!!**

- from here, make or edit the files you want to change with your desired text editor. i use vim so i type ```vim *FILENAME.ino*``` into my command line. then i edit the file. it doesn't matter what editor you use. save your edits.

- back in the command line, type ```git add *FILENAME.ino*```

- then type ```git commit -m "COMMIT MESSAGE"```

- type ```git push origin *YOURNAME*``` to officially commit your changes. good job! if you check github you will see it worked.

- If you feel confident that you aren't overwriting anyone else's code, switch to master and merge your branch to master. do this by typing ```git checkout master``` and then ```git merge *YOURNAME*``` then type ```git push origin master``` and you're done.

-overview after first setup:
```
cd lineFollower
git checkout *YOURNAME*
git pull
vim FILENAME.ino
*Make changes*
git add FILENAME.ino
git commit -m "COMMIT MESSAGE"
git push origin YOURNAME
```

if you feel confident in not overwriting code
```
git checkout master
git status
git merge *YOURNAME*
git push origin master
```
