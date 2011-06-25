mkdir src
cd src
git clone git@github.com:drupaljam/drupaljam.git
cd ..

SITEDIR=$(pwd)
cat src/drupaljam/build.make | sed -e "s|\(projects\[drupaljam\]\[download\]\[url\]\).*|\1 = file://$SITEDIR/src/drupaljam|" > build.make
