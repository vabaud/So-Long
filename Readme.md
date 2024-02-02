Commande pour executer valgrind sans les leaks de la MLX42 : valgrind --leak-check=full --keep-debuginfo=yes --suppressions=mlx42.supp ./so_long "maps/maps.ber"



         _              _        
        /\ \           /\ \      
       /  \ \         /  \ \     
      / /\ \_\       / /\ \_\    
     / / /\/_/      / / /\/_/    
    / / / ______   / / / ______  
   / / / /\_____\ / / / /\_____\ 
  / / /  \/____ // / /  \/____ / 
 / / /_____/ / // / /_____/ / /  
/ / /______\/ // / /______\/ /   
\/___________/ \/___________/    
                                 



A faire :
/mettre le message maps invalide quand il ya un retour a la lignes dans le .ber 
/gerer les lettres inconnue dans le .ber (sa fonctionne mettre si on met pas une bonne lettre)
/gerer si tout les collectibles sont accesible 
/gerer sit le chemin est bie valide (acces a la sortie)