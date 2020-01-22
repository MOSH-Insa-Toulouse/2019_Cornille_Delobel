Ce répertoire regroupe le travail effectué dans le module Micro-controllers Open Source Hardware, dispensé au sein de la formation ISS à l'INSA Toulouse. Vous y trouverez toutes les ressources induites par la réalisation du projet en autonomie: logiciel embarqué sur Arduino Uno, routage sous KiCad, interface Node Red.  

Le projet en autonomie consisté en plusieurs étapes, que nous avons réalisées de la piste verte à la piste noire.  

## Logiciel embarqué Arduino : Communication LoRa de la valeur relevée par le capteur

Dans un premier temps nous avons travaillé sur la réalisation d'un code Arduino dans lequel vous trouverez différentes étapes :   
	- la lecture du port analogique d'un capteur de gaz Seeed avec la fonction analogRead(). Pour ceci nous avons souhaité calibrer le capteur, ce qui a été difficilement réalisable puisque nous n'avions pas d'atmosphère de test pour les gaz détectés par ce capteur spécifique.   
	- la communication LoRa. Pour cela nous avons créé une application et un device sur la plateforme The Things Network et avons établi la communication par le port TX avec la fonction myLora.tx().   
	- la réalisation d'une interruption. Nous avons ici travaillé sur la réalisation d'une interruption hardware selon la valeur relevée par le capteur. Pour cela, nous avons réalisé un montage comparateur à base d'AOP et avons ensuite utilisé la fonction attachinterrupt() pour envoyer un message de danger sur la plateforme lorsque le seuil est dépassé.   

## Consommation énergétique 

Nous nous sommes ensuite intéressés à la consommation d'énergie de notre circuit. Pour cela, nous avons mesuré la consommation du montage AOP qui semble se réduire à la consommation de l'AOP, autour de 1mA.    
Ensuite nous avons pu mesurer, à l'aide d'un module USB dédié, la consommation du circuit total. Nous avons effectué des tests avec et sans interruption et sommes parvenus à la conclusion que la communication LoRa consomme 10mA environ et avons confirmé l'hypothèse selon laquelle la consommation du montage comparateur était négligeable.    

## Routage KiCad 

Le routage KiCad a été réalisé à partir du circuit analogique ainsi réalisé, comprenant le capteur, le montage comparateur, un montage amplificateur et le module LoRa. Vous pouvez trouver les fichiers de conceptions dans le dossier KiCad.    

## Node Red

Nous avons finalement travaillé sur la réalisation d'une interface permettant de visualiser les résultats. Nous avons utilisé node-red et la librairie ttn afin de récupérer les valeurs envoyées à la plateforme et créer un dashboard présentant le résultat sous forme de jauge.    
