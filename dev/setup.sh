mkdir src
cd src
git clone git@github.com:drupaljam/drupaljam.git
cd ..

SITEDIR=$(pwd)
cat src/drupaljam/build.make | sed -e "s|\(projects\[drupaljam\]\[download\]\[url\]\).*|\1 = file://$SITEDIR/src/drupaljam|" > build.make

mkdir data
chmod a+w data

mkdir config

drush make build.make build
cp build/sites/default/default.settings.php config/settings.php
cd build/sites/default
ln -s ../../../config/settings.php .
ln -s ../../../data files

cd ../../..
ln -s src/drupaljam/dev/build.sh .
