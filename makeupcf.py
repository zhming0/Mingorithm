import os
import shutil
cfdir = '/Users/M/Documents/Xcode Projects/Codeforces'
targetdir = '/Users/M/Desktop/Algorithm/Codeforces'
dirlist = os.listdir(cfdir)
for i in dirlist:
	if i[0]=='.' or os.path.isdir(cfdir + '/'+ i)!=True:
		continue
	targetname = i+'.py';
	tmppath = cfdir+'/'+i
	tmplist = os.listdir(tmppath+'/'+i)
	if tmplist.count('main.cpp') == 1:
		shutil.copy(tmppath+'/'+i+'/main.cpp', targetdir+'/'+targetname)