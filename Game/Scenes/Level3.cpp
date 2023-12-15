#include "DefaultScene.h"

void DefaultScene::SpawnObjectLevel3() {
    sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

    SetTexture("background", "Assets/background/level_3_background.png");
    SetBackground("background");

    int sizeX = window_size.x / 100;
    int sizeY = window_size.y / 100;

   /* CreateSwitch(this, SwitchType, "Switch", 13 * sizeWallX, 15 * sizeWallY);*/

    //Etagère + livres
    CreateColliderObject(this, ColliderType, "Wall", Maths::Vector2f(sizeX * 4.6875, sizeY * 45.33), Maths::Vector2f(sizeX * 15.875, sizeY * 1.44));

    //Okay reteste avec l'etagere en cliquant en hautgauche et bas droite pour voir si c'est les meme valeur
    //alors ?
    // je vois pas le terminal mdr
    //ca me l'ouvre plus apres toi regarde si c'est environ les meme 
    //je le vois pas non plus
    // ton terminal s'ouvre ou pas ?
    //si c'est bon, mais ça me mettait juste "1"
    // okay relance et dit moi si "r"
    //yes
    //okay reteste et regarde le chiffre apres "r"
    //j'ai compris mon erreur ca devrait marcher la 
    //1, juste r = 1

    // okay la c'est bon normalement fait   2 clic 
    //ca affiche que si tu as fait 2 clic
    //ca genere, c'est long
    //ouai je vois ca
    //4 45 15 1
    // ah ok juste il affiche pas les virgule c'est chiant
    // reassye voir si 

    //CreateColliderObject(this, ColliderType, "Wall", 3 * sizeWallX, 10 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 10 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 5 * sizeWallX, 10 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 6 * sizeWallX, 10 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 6 * sizeWallX, 9 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 6 * sizeWallX, 8 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 6 * sizeWallX, 7 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 5 * sizeWallX, 9 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 5 * sizeWallX, 8 * sizeWallY);

    ////Table de chevet
    //CreateColliderObject(this, ColliderType, "Wall", 1 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 2 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 3 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 17 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 18 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 19 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 4 * sizeWallX, 20 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 3 * sizeWallX, 20 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 2 * sizeWallX, 20 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 1 * sizeWallX, 20 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 1 * sizeWallX, 19 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 1 * sizeWallX, 18 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 1 * sizeWallX, 17 * sizeWallY);

    ////Ours
    //CreateColliderObject(this, ColliderType, "Wall", 8.5 * sizeWallX, 12 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 8.5 * sizeWallX, 13 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 8.5 * sizeWallX, 14 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 9 * sizeWallX, 15 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 9 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 8 * sizeWallX, 17 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 10.5 * sizeWallX, 13 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 10.5 * sizeWallX, 14 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 10.5 * sizeWallX, 15 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 10.5 * sizeWallX, 16 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 11 * sizeWallX, 17 * sizeWallY);

    ////Fenêtre
    //CreateColliderObject(this, ColliderType, "Wall", 9.5 * sizeWallX, 12 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 10.5 * sizeWallX, 12 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 11.5 * sizeWallX, 12 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 12.5 * sizeWallX, 12 * sizeWallY);
    //CreateColliderObject(this, ColliderType, "Wall", 13.5 * sizeWallX, 12 * sizeWallY);



    //Bibliothèque
    //CreateColliderObject(this, ColliderType, "Wall", 20 * sizeWallX, 12 * sizeWallY);
}