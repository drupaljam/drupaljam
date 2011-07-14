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

TODO: Verder uitwerken wat te doen als je eenmaal een werkende omgeving hebt.

**Disclaimer: Deze workflow is getest op Mac OSX Snow Leopard. Het zou moeten 
werken exact hetzelfde moeten werken op elke andere versie van Mac OSX. Verder
verwacht ik geen grote problemen met Linux of andere Unix varianten, maar daar
heb ik niet op getest. [Git](http://git-scm.com/), 
[drush](http://drupal.org/project/drush) and 
[drush_make](http://drupal.org/project/drush_make) moeten geïnstalleerd zijn.**
