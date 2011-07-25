# make sure the source dir is present. If there is no source dir, we clone it 
# from the drupaljam github repository
if [ ! -d src ] ; then
	mkdir src
	cd src
	git clone git@github.com:drupaljam/drupaljam.git
	cd ..
fi

# make sure we have a build.make file. If there is no build.make file we create 
# one that is derived from the build.make in the source directory. We rewrite
# the drupaljam download url to the local repository in the source directory
# to be able to build completely locally
if [ ! -f build.make ] ; then
	SITEDIR=$(pwd)
	cat src/drupaljam/build.make | sed -e "s|\(projects\[drupaljam\]\[download\]\[url\]\).*|\1 = file://$SITEDIR/src/drupaljam|" > build.make
fi

# Make sure a writable data directory is available
if [ ! -d data ] ; then
	mkdir data
	chmod a+w data
fi

# Manage old builds. When we build, we build to the 'build' directory. Before
# this, we rename the existing 'build' directory (if any) to 'build_old'. 
# 'build_old' gets removed.
if [ -d build ] ; then 
	if [ -d build_old ] ; then
		rm -r build_old
	fi
	
	mv build build_old
fi

# drush make the installation
drush make build.make build

# Make sure we have a configuration directory. If it doesn't exist, create one
# and copy the default settings into it.
if [ ! -d config ] ; then
	mkdir config
	cp build/sites/default/default.settings.php config/settings.php
	chmod a+w config/settings.php
fi

# symlink the settings.php and data directory into the new build
cd build/sites/default
ln -s ../../../config/settings.php .
ln -s ../../../data files
cd ../../..

# symlink this script into the main directory, because this script also can
# create new build while leaving everything else intact
ln -s src/drupaljam/dev/setup.sh .