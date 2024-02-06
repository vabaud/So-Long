Commande pour executer valgrind sans les leaks de la MLX42 : valgrind --leak-check=full --keep-debuginfo=yes --suppressions=mlx42.supp ./so_long "maps/maps.ber"


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



❌❌❌❌
/mettre le message maps invalide quand il ya un retour a la lignes dans le .ber 
/gerer les lettres inconnue dans le .ber (sa fonctionne meme si on met pas une bonne lettre)
/gerer si tout les collectibles sont accesible 
/gerer sit le chemin est bien valide (acces a la sortie)
/gerer si ya rien dans le .ber
/gerer si la maps nest pas rectangulaire
/gerer quand ya pas le perso sur la maps 'P' (1leaks)
/retourner une erreur qund ya pas de sortie 
/verifier si dautre carte .ber sa fonctionne correctement
/retourner une erreur quand ya pas de player sur la maps




Mlx put string pour afficher le nombre de mouv sur lecran




✅✅✅✅
/2 barril en meme temps sur la maps (0leaks) (le 2eme bouge pas)
/qund ya pas que des 1 autour de la maps (0leak)
/quand ya pas de collectible (la porte est dirrectement ouverte) (0leak)




jai ajouter exit(0) a la fonctions condition pour sortir du jeu qund jappuie sur la touche esc (jai limpression que cest plus rpide mais je ne suis pas vraiment sur)





void	display_number(t_all *all, int nb_move, int32_t x, int32_t y)
{
	char mouv[50];
	move(all);
	sprintf(mouv, "%d", all->move.nb_move);
	mlx_put_string(all->mlx, mouv, x, y);
}