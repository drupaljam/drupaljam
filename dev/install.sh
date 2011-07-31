DEFAULT=$(cat build/sites/default/default.settings.php | md5)
CURRENT=$(cat config/settings.php | md5)

echo $DEFAULT $CURRENT

OPTIONS=""
APPROVED=0
if [ $DEFAULT = $CURRENT ]; then
	echo "This is the first time you install the DrupalJam project." \
		"Therefore you will need to specify information about your" \
		"database connection. Please enter credentials that allow you" \
		"to create and drop databases."
	while [ $APPROVED = 0 ]; do
		echo -n "Hostname (default: localhost): "
		read HOSTNAME
		if [ ! $HOSTNAME ]; then 
			HOSTNAME=localhost
		fi
	
		echo -n "Username (default: root): "
		read USERNAME
		if [ ! $USERNAME ]; then
			USERNAME=root
		fi
	
		echo -n "Password (default: <none>): "
		read PASSWORD
	
		echo -n "Database (default: drupaljam): "
		read DATABASE
		if [ ! $DATABASE ]; then
			DATABASE=drupaljam
		fi
	
		URL="mysql://$USERNAME:$PASSWORD@$HOSTNAME/$DATABASE"
		
		echo "The MySQL URL is going to be $URL."
		SET=0
		while [ $SET = 0 ]; do
			echo -n "Is this correct? (y/n): "
			read INPUT
			if [ $INPUT = "y" ]; then
				SET=1
				APPROVED=1
			else
				SET=1
			fi
		done
	done
	
	OPTIONS="$OPTIONS --db-url=$URL"
fi

cd build
drush site-install drupaljam$OPTIONS
