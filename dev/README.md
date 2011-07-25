**Deze instructies zijn bedoeld voor de teamleden. Als je werkt vanuit je eigen
fork, kan het zijn dat sommige zaken anders lopen.**

We werken met een install profile en drush make georienteerde workflow. Het doel
is ALLE configuratie in code te plaatsen, zodat we eenvoudigweg het DrupalJam
install profile kunnen installeren (misschien wel met Aegir) op een subdomein,
zoals hilversum2011.drupaljam.nl.

Om je ontwikkelomgeving op te bouwen voor de DrupalJam site, maak je een 
directory aan waar je normaal gesproken ook je projecten maakt, bijvoorbeeld
`~/Sites/DrupalJam`. In deze directory voer je het volgende commando uit.

```bash
curl https://raw.github.com/drupaljam/drupaljam/master/dev/setup.sh | sh
```

Dit commando creeert een aantal mappen en bestanden in de directory waar je het
draait.

* **```build/```** is een directory waarin een volledige Drupal 7 installatie is 
  opgebouwd. Als je de inhoud hiervan bekijkt zie je de vertrouwde 
  ```includes/```, ```misc/```, ```modules/```, ```scripts/```, ```sites/``` en 
  ```themes/``` map en de bestanden van Drupal.
* **```build.make```** is een make bestand voor Drush Make die gebaseerd is op 
  de ```build.make``` die op Github staat. Deze geeft Drush Make genoeg 
  informatie om de ```build/``` directory op te bouwen op basis van je lokale
  Git repository, in plaats van op basis van de Github repository.
* **```config/```** is een directory waarin je configuratie wordt opgeslagen. Om
  te voorkomen dat je je ```settings.php``` kwijt bent nadat je een nieuwe build 
  met Drush Make gedraaid hebt, wordt de ```settings.php``` door ```setup.sh```
  in een aparte directory geplaatst en als symlink in ```build/sites/default/```
  gezet.
* **```data/```** is een directory waarin Drupal je files opslaat. Om dezelfde
  redenen en op dezelfde manier als je ```settings.php``` wordt deze buiten de
  ```build/``` directory gehouden.
* **```setup.sh```** is een symlink naar ```src/drupaljam/dev/setup.sh```. Dit
  is hetzelfde script als waarmee je deze omgeving hebt opgebouwd. Dit script 
  kun je, onder andere, gebruiken om een nieuwe build te maken.
* **```src/```** is een directory waar de eigenlijke source wordt opgeslagen. 
  Deze directory bevat een directory met de naam ```drupaljam/```. Dit is een 
  clone van de Github repository.
  
drwxr-xr-x   8 rolf  staff   272B Jul 25 21:32 .
drwxr-xr-x   7 rolf  staff   238B Jul 25 21:31 ..
drwxr-xr-x  29 rolf  staff   986B Jul 25 21:32 build
-rw-r--r--   1 rolf  staff   222B Jul 25 21:32 build.make
drwxr-xr-x   3 rolf  staff   102B Jul 25 21:32 config
drwxrwxrwx   2 rolf  staff    68B Jul 25 21:32 data
lrwxr-xr-x   1 rolf  staff    26B Jul 25 21:32 setup.sh -> src/drupaljam/dev/setup.sh
drwxr-xr-x   3 rolf  staff   102B Jul 25 21:32 src

TODO: Verder uitwerken wat te doen als je eenmaal een werkende omgeving hebt.

**Disclaimer: Deze workflow is getest op Mac OSX Snow Leopard. Het zou moeten 
werken exact hetzelfde moeten werken op elke andere versie van Mac OSX. Verder
verwacht ik geen grote problemen met Linux of andere Unix varianten, maar daar
heb ik niet op getest. [Git](http://git-scm.com/), 
[drush](http://drupal.org/project/drush) and 
[drush_make](http://drupal.org/project/drush_make) moeten geïnstalleerd zijn.**
