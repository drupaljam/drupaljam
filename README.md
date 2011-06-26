# DrupalJam

We are currently creating the new site for the DrupalJam here. DrupalJam is the
go-to event for Drupal enthusiastics in the Netherlands and Belgium. 

This new site is an effort to port the existing site to Drupal 7 and meanwhile 
fix a few things that annoy us on the current site.  

## Getting started

We work with a install profile and a drush make oriented development workflow. 
The goal is to put ALL configuration in code, so that we can simply install the
DrupalJam install profile (maybe even with Aegir) on hilversum2011.drupaljam.nl.

To setup your development environment, you create a directory for the DrupalJam
project where you would normally create your projects, something like 
`~/Sites/DrupalJam`. In that directory you run the following command.

```bash
curl https://raw.github.com/drupaljam/drupaljam/master/dev/setup.sh | sh
```

More information on this follows.

**Disclaimer: This workflow is tested on Mac OSX Snow Leopard. It should work 
exactly the same on any other Mac OSX version. It requires Git to be installed. 
On Linux and other Unixes it should work the same, but I didn't perform any test
for that at all.**

