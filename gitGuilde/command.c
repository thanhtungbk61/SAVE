1. create repository
    git init
2. add file
    git add "fileName" or -all
    git commit -m "messgage"
add to remote repository
    git push -u origin main
3. log
3.1 git log -p -2
    ==> take 2 commit 
3.2 git log --stat
    ==> more clearly
    
3.2 git log  --pretty=oneline
    ==> see short log
3...
    git log --since=2.weeks
    git log --since- "2008-10-01"

4. add to previous commit with no message 
(when you forget some file or need to add more file 
with same message as previous commit)
    git commit --amend
5 un staged for this commit
(when you want to commit some part of project, not all file, but you do a command
    git add * ==> so you need to un staged some file or folder)
    git reset HEAD "fileName"

6. unmodify a modified file
    git checkout

7. test unmodify
exit: -q

8. work with remote repository
8.1 clone repository
	git clone url (default master branch)
	git remote -v ( see information of repository)
8.2 add local repository to remote repository
	git init (create repository first)
	git remote add "name" url ( name use can set to origin)
8.3 fetching and pulling
	git fetch (see what new in remote repository)
	git pull  "name" "branch" (loading remote repository to local repository)
	(git pull origin master)
	==> modify 
	git add *
	git commit -m "message"
	git push "name" "branch"
	(git push origin master)
10 create tag ( tag github understand as realese)
	(tag name usually like v1.0 ...)
	git tag -a "name tag" -m "message"

	git tag (show all your tag)\
	git show "name tag" (show more detail of tag)

	git push origin --tags ( push to remote)
	// delete tag
	git tag -d "tag name"  (local)
	git push origin --delete "tag name" (remote)
	git --detele "tag name"

###
other command 

    git status
    git clone url
    git rename "new name"
    git remote  rm "name"

    git checkout "name"
    git check out v1.0 (create branch v1)
