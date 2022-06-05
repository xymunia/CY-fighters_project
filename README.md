# CY-fighters_project
Projet d'informatique à cy tech

Pour lancer le programme:
--

lancer le terminal et aller dans le répertoire correspondant.
entre les commandes suivantes: 

    make
    ./exec
                                

Déroulement du programme:
--

Le jeu se lance avec le professeur vous demandant votre nom de dresseur et vous proposant le choix entre 3 pokemons...



Vous avez alors le choix entre 2 types de combat:


Combat sauvages:
--

   Un combat où vous affronter 2 pokémons sauvages, avec votre équipe.
   Dans ce mode, vous pouvez essayer de capturer les pokemons vous opposants tant que vous n'aveez pas dépasser la limite de 6.
    


Combat de dresseurs:
--
Un combat où vous affronter un dresseur avec une équipe de pokemons, son nombre de pokemons augmentera à chaque victoire jusqu'à atteindre 6.
   Dans ce mode, vous ne pouvez pas attraper les pokemons adverses. De plus, le dresseur changera ses pokemons lorsque ceux en combat seront ko.
   
  
  
Combat:
--

  Le combat fonctionne en 2 contre 2, avec un système de vitesse pour déterminer quels pokemons jouent lors d'un tour.
  Lors de chaque tour, une valeur de vitesse prédéfini sera ajouté à la barre de vitesse de chaque pokemon, selon si la valeur de la barre de vitesse a dépassé un       certain seuil, le pokemon jouera ce tour. 
  Dans le cas où plusieurs pokemons jouent ce tour, tous les pokémons jouent, dans l'ordre décroissant par rapport à leur valeur de barre de vitesse.
  
  Chaque pokemon a accès à la capacité struggle, capacité de base qui fait très peu de dégâts et enlève un quart des pv en contrecoup (il est donc déconseillée d'utiliser cette capacité)
  
  Un pokemon peut avoir 1 à 2 types, qui peuvent influer sur les dégâts d'une capacité selon le type de la capacité.
  Un pokemon peut effectuer esquiver une attaque, infliger un coup critique, infliger un statut si ses capacités lui permettent d'en infliger.
  
  
  
  
  
