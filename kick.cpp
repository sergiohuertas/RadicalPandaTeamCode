//sf::Clock *clock;

void kick(){
    
    if(clock->getElapsedTime>=5){
        if(pl->getFacing()==0){
            attack(pl->getPosition().x-30);
        }
        if(pl->getFacing()==1){
            attack(pl->getPosition().y-30);
        }
        if(pl->getFacing()==2){
            attack(pl->getPosition().x+30);
        }
        if(pl->getFacing()==3){
            attack(pl->getPosition().y+30);
        }
    }
     clock.restart();   
    
}

