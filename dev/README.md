# Development

**Deze instructies zijn bedoeld voor de teamleden. Als je werkt vanuit je eigen
fork, kan het zijn dat sommige zaken anders lopen.**

We werken met een install profile en drush make georienteerde workflow. Het doel
is ALLE configuratie in code te plaatsen, zodat we eenvoudigweg het DrupalJam
install profile kunnen installeren (misschien wel met Aegir) op een subdomein,
zoals hilversum2011.drupaljam.nl.

## Omgeving opbouwen

Om je ontwikkelomgeving op te bouwen voor de DrupalJam site, maak je een 
directory aan waar je normaal gesproken ook je projecten maakt, bijvoorbeeld
`~/Sites/DrupalJam`. In deze directory voer je het volgende commando uit.

```bash
curl https://raw.github.com/drupaljam/drupaljam/master/dev/setup.sh | sh
```

Dit commando creëert een aantal mappen en bestanden in de directory waar je het
draait.

* `build/` is een directory waarin een volledige Drupal 7 installatie is 
  opgebouwd. Als je de inhoud hiervan bekijkt zie je de vertrouwde 
  `includes/`, `misc/`, `modules/`, `scripts/`, `sites/` en 
  `themes/` map en de bestanden van Drupal.
* `build.make` is een make bestand voor Drush Make die gebaseerd is op 
  de `build.make` die op Github staat. Deze geeft Drush Make genoeg 
  informatie om de `build/` directory op te bouwen op basis van je lokale
  Git repository, in plaats van op basis van de Github repository.
* `config/` is een directory waarin je configuratie wordt opgeslagen. Om
  te voorkomen dat je je `settings.php` kwijt bent nadat je een nieuwe build 
  met Drush Make gedraaid hebt, wordt de `settings.php` door `setup.sh`
  in een aparte directory geplaatst en als symlink in `build/sites/default/`
  gezet.
* `data/` is een directory waarin Drupal je files opslaat. Om dezelfde
  redenen en op dezelfde manier als je `settings.php` wordt deze buiten de
  `build/` directory gehouden.
* `install.sh` is een symlink naar `src/drupal/dev/install.sh`. Dit script kun 
  je gebruiken om een nieuwe install te maken vanuit de huidige build directory.
* `setup.sh` is een symlink naar `src/drupaljam/dev/setup.sh`. Dit
  is hetzelfde script als waarmee je deze omgeving hebt opgebouwd. Dit script 
  kun je, onder andere, gebruiken om een nieuwe build te maken.
* `src/` is een directory waar de eigenlijke source wordt opgeslagen. 
  Deze directory bevat een directory met de naam `drupaljam/`. Dit is een 
  clone van de Github repository.

De tweede stap is het instellen van Apache en je `/etc/hosts` file. Maak, zoals
je dat normaal gesproken doet, Apache configuratie aan met als DocumentRoot de
`build/` directory in je project.

De volgende stap is de installatie van Drupal op basis van het DrupalJam install
profile. Daarvoor is het `install.sh` script een handig hulpmiddel. Onder water 
roept deze slechts `drush site-install drupaljam` aan. De handigheid aan 
`install.sh` is dat deze eerst controleert of je al een gevulde settings.php 
hebt. Als je die nog niet hebt, zal het script je vragen om de database 
instellingen. Je moet een database username en password opgeven dat genoeg 
rechten heeft om databases toe te voegen en te verwijderen.

Voer dus het volgende commando uit in je project directory (dezelde directory
waar je het vorige commando hebt uitgevoerd) en vul je database gegevens in.

```bash
./install.sh
```

## Werken in de opgebouwde omgeving

Nu je een werkende installatie hebt, kun je naar de URL gaan die je ingesteld 
hebt in Apache en zie je de huidige versie van de site.

Deze site kun je vervolgens aanpassen, zoals je elke andere site aanpast. Je 
moet je echter wel realiseren dat alle configuratie in code moet komen te staan
en dat de source uitsluitend het install profile is. Het toevoegen van een 
contrib module gebeurd dus niet door de gehele code van de module toe te voegen
aan de git repository, maar door de module toe te voegen aan `drupaljam.make` 
(om de package te downloaden bij een build) en aan  `drupaljam.info` (om de 
module in te schakelen bij het installeren van de site). Voor configuratie kun je
Features gebruiken. 

Het tweede wat je je moet realiseren is, dat je nu twee Git repositories lokaal
hebt.

* `src/drupaljam` is een clone van de `drupaljam/drupaljam` GitHub 
  repository.
* `build/profiles/drupaljam` is een clone van bovenstaande repository.

Op zich is het mogelijk om te ontwikkelen met maar één repository (de eerste).
Het nadeel daarvan is echter dat je voor elke kleine code-wijziging een nieuwe
build moet maken. In veel gevallen is dat helemaal niet nodig. De tools die met
deze constructie tot je beschikking hebt zijn de volgende.

* `./setup.sh` in de Project directory. Dit draait een nieuwe `build` vanuit je 
  huidige `src/drupaljam` repository. Om wijzigingen in de nieuwe `build` mee te
  nemen, moet het gecommit zijn in je `src/drupaljam` repository.
* `./install.sh` in de Project directory. Dit commando herinstalleerd Drupal met
  de huidige `build`.
* `git commit` in de `src/drupaljam` repository.
* `git commit` in de `build/profiles/drupaljam` repository.
* `git pull origin` in de `build/profiles/drupaljam` repository haalt de commits
  uit de `src/drupaljam` repository op. Als je alleen wijzigingen gedaan hebt 
  aan code en niet aan `drupaljam.make` of `drupaljam.info` heb je in veel
  gevallen geen nieuwe `build` in installatie nodig. 
* `git pull build` in de `src/drupaljam` repository haalt de commits uit de
  `build/profiles/drupaljam` repository op. Je kunt ervoor kiezen om zaken 
  direct in de build te wijzigen en daar te committen (eventueel zelfs pas na
  testen). Vervolgens kun je deze commits naar de `src/drupaljam` repository
  halen, zodat je ze door kunt sturen naar GitHub.
* `git push` in de `src/drupaljam` repository stuurt je commits door naar de
  DrupalJam repository op GitHub.

**Disclaimer: Deze workflow is getest op Mac OSX Lion. Het zou moeten exact 
hetzelfde moeten werken op elke andere versie van Mac OSX. Verder verwacht ik 
geen grote problemen met Linux of andere Unix varianten, maar daar heb ik niet 
op getest. [Git](http://git-scm.com/), [drush](http://drupal.org/project/drush) 
and  [drush_make](http://drupal.org/project/drush_make) moeten geïnstalleerd
zijn.**
