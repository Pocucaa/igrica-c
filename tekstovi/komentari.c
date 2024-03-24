
//Sredjivanje interfejsa, sve to doraditi da bude cakum pakum
//Sredjivanje koda, da bude pregledniji
















//dodati tajmer na kraju svega da izgleda bolje
/* Napravi boss ight kada se ukuca ime bosa i level je preko 10
napravi da svaki heroj ima abiliti za kretnju na primer i da ase taj abiliti aninmira putem coooldwona
dodati cooldown za stvari i mozda pokusati da animiras fajt kao pokemone sa grafickim iterfejsom
saman stavi totem T?
napravi X na mapi koji ti daje tu infomraciju za bosa i uvek je moguce doci do njega
*/ //da li se cudovista pomeraju kada koristis stats?

/*      IDEJE ZA AJTEME
sword= +~ minimum damage                    4
axe= +~ max damage (vece)                      4
dagger= min crit chase                             4 varijacieje     
mage staff=  +~ minimum medit                       4
bronze, iron, gold, diamond chestplate = (50% chanse to block 2/4/8/10 damage)
amethyst amulet= gain 2 mana per turn in combat
tiger eye= heal 2 health per turn   
opalit= meditate + 5
sythe= rand damage addon 2-10? mozda jos koji ajtem na tu foru
bronze, iron, gold, diamond helmet= (bonus 10/20/40/80 max hp)      *dodati max hp mehaniku
helmet of zephyr= end of turn deal 5 damage

warrior dual blade?

lightning rod= start of combat, deal 30 damage
fire blade= max damage + mnogo

katana= 5 min damage and also 12 damage
dragon claw= end of combat heal 10

*/

// sredi da yes or no bude y ili n
//dodati ambijentalni text na odredjenim tajlovima

//Protekcija koda

//komentari za levele u jednom txt fajlu, pa citanje u zavisnosti od lvl

//chara pl4 = {30, 20, "shaman"};

//proveriti da li radi getchar za stvari na pocetku i borbu

//nauci povezivanje funkcija preko externih fajlova, pogledaj onu dungeon igricu na githubu, kreni da stancas github

//dodati da kada pogresis input ne procesuira funkicju, da kada se zavrsi borba sve prodje kako treba, da se invokuje lvl up funkcija ispod borba funkicje,

//dodati save opciju

//BITNO***********************
//Dodavanje spelova u strukture itd,svaki spell svoja funkcija ok, sta raditi sa rezultatom?



		
	/*typedef struct{
		char iname;
		int itru;
		} item;*/







/*rogue spel2 
become invisible for 3/3/4/4 turns, monsters cant see message,
i deals 0 damage oke zbog kalkulacije ako ima msg pre toga taj
level 5= kada je roguespl2 na 5, hilaj se ta 2 turna

rogue ultimate 
steal 5 gold from enemy
jako veliki mana cost
delaj 40\50\70 demidza ne znam videcemo
hiluj se 12/24/48 HP
take 0 damage, dodge attack

warrior spel1
gain 20/30/40/50 shield
deal 70& attack
heal 30% damage (zaokruzi u funkciji)

warrior spel2
take 20% hp damage (ili neki damage od enemija uvecan)
gain 0.7 x HP + 20~ shield

warrior ultimate
Engaged warrior
for 5 turns:
- 20% damage
- heal 10HP
- gain 20 shield
- 1.5 40% crit chanse?

mage spel1
Raining fountain
for 5 turns:
-heal 5 HP
-gain 20% medit

mage sepl2
Black madness
- deal 0.7 * AT + 1.3 * medit + 20 damage

mage ultimate
electric field
for 5 turns:
-deal 50 damage
-30% medit
-gain 3 mana

MEHANIKE

counter mehanika koja se setuje na kraju na 0 da meri turnove da
mogu abilitiji da traju nekoliko turnova

ulti se moze iskoristiti samo jednom u borbi,
eventualno 2 kad se dobro levelujes, mozda i vise

naravno imas spel kaunter i mozes da levelujes magije na razlicite 
levele i imas skill kanter da rokas stats, samo sto za svaki levelup,
njih dobijas vise



rogue
dodge mehanika -> dodge funkcije -> random na dodge promenjivu

warrior
shield, na pocetku dodati dodatak za warriora a to je shield. on je 0/0 
ali nije los pasiv i da imaju vise pasiva
magije daju shield, razlika se prvo oduzima od shielda pa onda od helta

mage
meditating restores mana :D

----------------------------------
dakle:
rogue:
-chanse to crit
-dodge chanse

warrior:
an eye for an eye
gains 50% damage when below 50% health
shield mehanika

mage:
chanse to zap enemy before fight, dealing minor damage
meditating restores mana
----------------------------------

*/


/*
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int distance;
} Node;

int isWalkable(int map[MAP_SIZE_X][MAP_SIZE_Y], int x, int y) {
    return (x >= 0 && x < MAP_SIZE_X && y >= 0 && y < MAP_SIZE_Y && map[x][y] == 1);
}

int calculateDistance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node createNode(int x, int y, int distance) {
    Node node;
    node.x = x;
    node.y = y;
    node.distance = distance;
    return node;
}

Hero moveNPC(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY, Hero *hero, mon mon, char *name, int exps, int golds) {
    int sight_range = 15;
    int enemy_i, enemy_j;

    for (int k = 0; k < MAP_SIZE_X; k++) {
        for (int l = 0; l < MAP_SIZE_Y; l++) {
            if (map[k][l] == 3) {
                enemy_i = k;
                enemy_j = l;

                double distance = sqrt(pow(playerX - enemy_i, 2) + pow(playerY - enemy_j, 2));

                if (distance <= sight_range) {
                    // Player is within sight range; move towards the player using A* pathfinding.
                    Point start = {enemy_i, enemy_j};
                    Point end = {playerX, playerY};
                    Node openList[MAP_SIZE_X * MAP_SIZE_Y];
                    Node closedList[MAP_SIZE_X][MAP_SIZE_Y];
                    int foundPath = 0;

                    int openListSize = 0;
                    openList[openListSize++] = createNode(start.x, start.y, 0);

                    while (openListSize > 0) {
                        // Implement A* pathfinding logic here.
                    }

                    if (foundPath) {
                        // Move the enemy along the found path.
                    }
                } else {
                    // Player is not in sight; move randomly.
                    int random_direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right

                    if (random_direction == 0 && isWalkable(map, enemy_i - 1, enemy_j)) {
                        // Move up
                        // Implement random movement logic here.
                    } else if (random_direction == 1 && isWalkable(map, enemy_i + 1, enemy_j)) {
                        // Move down
                        // Implement random movement logic here.
                    } else if (random_direction == 2 && isWalkable(map, enemy_i, enemy_j - 1)) {
                        // Move left
                        // Implement random movement logic here.
                    } else if (random_direction == 3 && isWalkable(map, enemy_i, enemy_j + 1)) {
                        // Move right
                        // Implement random movement logic here.
                    }
                }
            }
        }
    }
} */






/*

// Define the Hero and mon structures here

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int x;
    int y;
    int distance;
} Node;

int isWalkable(int map[MAP_SIZE_X][MAP_SIZE_Y], int x, int y) {
    return (x >= 0 && x < MAP_SIZE_X && y >= 0 && y < MAP_SIZE_Y && map[x][y] == 1);
}

int calculateDistance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node createNode(int x, int y, int distance) {
    Node node;
    node.x = x;
    node.y = y;
    node.distance = distance;
    return node;
}

// Helper function to find the index of a node with the lowest f value in the open list
int findLowestF(Node openList[], int openListSize) {
    int lowestFIndex = 0;
    for (int i = 1; i < openListSize; i++) {
        if (openList[i].distance < openList[lowestFIndex].distance) {
            lowestFIndex = i;
        }
    }
    return lowestFIndex;
}

// A* pathfinding function
int findPath(int map[MAP_SIZE_X][MAP_SIZE_Y], Point start, Point end, Point path[], int *pathLength) {
    Node openList[MAP_SIZE_X * MAP_SIZE_Y];
    Node closedList[MAP_SIZE_X][MAP_SIZE_Y];
    int foundPath = 0;

    int openListSize = 0;
    openList[openListSize++] = createNode(start.x, start.y, 0);

    while (openListSize > 0) {
        int current = findLowestF(openList, openListSize);
        Node current_node = openList[current];
        openListSize--;
        openList[current] = openList[openListSize];

        int x = current_node.x;
        int y = current_node.y;

        if (x == end.x && y == end.y) {
            foundPath = 1;
            break;
        }

        closedList[x][y] = current_node;

        // Explore neighbor nodes
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (!isWalkable(map, new_x, new_y)) {
                continue;
            }

            int tentative_g = current_node.distance + 1;
            int tentative_f = tentative_g + calculateDistance((Point){new_x, new_y}, end);

            if (closedList[new_x][new_y].distance == 0 || tentative_f < closedList[new_x][new_y].distance) {
                openList[openListSize++] = createNode(new_x, new_y, tentative_f);
                closedList[new_x][new_y] = createNode(current_node.x, current_node.y, tentative_f);
            }
        }
    }

    // Reconstruct the path
    if (foundPath) {
        int length = 0;
        while (current_node.x != start.x || current_node.y != start.y) {
            path[length++] = (Point){current_node.x, current_node.y};
            current_node = closedList[current_node.x][current_node.y];
        }
        path[length++] = start;
        *pathLength = length;

        // Reverse the path
        for (int i = 0; i < length / 2; i++) {
            Point temp = path[i];
            path[i] = path[length - i - 1;
            path[length - i - 1] = temp;
        }
    }

    return foundPath;
}

void moveNPCWithAStar(int map[MAP_SIZE_X][MAP_SIZE_Y], int playerX, int playerY, Hero *hero, mon mon, char *name, int exps, int golds) {
    int sight_range = 15;
    int enemy_i, enemy_j;

    for (int k = 0; k < MAP_SIZE_X; k++) {
        for (int l = 0; l < MAP_SIZE_Y; l++) {
            if (map[k][l] == 3) {
                enemy_i = k;
                enemy_j = l;

                double distance = sqrt(pow(playerX - enemy_i, 2) + pow(playerY - enemy_j, 2);

                if (distance <= sight_range) {
                    // Player is within sight range; move towards the player using A* pathfinding.
                    Point start = {enemy_i, enemy_j};
                    Point end = {playerX, playerY};
                    Point path[MAP_SIZE_X * MAP_SIZE_Y];
                    int pathLength = 0;

                    if (findPath(map, start, end, path, &pathLength)) {
                        // Implement the logic to move the enemy along the path.
                        // You can use the 'path' array to move step by step.
                        if (pathLength > 0) {
                            enemy_i = path[0].x;
                            enemy_j = path[0].y;
                            map[enemy_i][enemy_j] = 3;
                            map[start.x][start.y] = 1;
                        }
                    }
                } else {
                    // Player is not in sight; move randomly.
                    int random_direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right

                    if (random_direction == 0 && isWalkable(map, enemy_i - 1, enemy_j)) {
                        // Move up
                        map[enemy_i][enemy_j] = 1;
                        enemy_i -= 1;
                        map[enemy_i][enemy_j] = 3;
                    } else if (random_direction == 1 && isWalkable(map, enemy_i + 1, enemy_j)) {
                        // Move down
                        map[enemy_i][enemy_j] = 1;
                        enemy_i += 1;
                        map[enemy_i][enemy_j] = 3;
                    } else if (random_direction == 2 && isWalkable(map, enemy_i, enemy_j - 1)) {
                        // Move left
                        map[enemy_i][enemy_j] = 1;
                        enemy_j -= 1;
                        map[enemy_i][enemy_j] = 3;
                    } else if (random_direction == 3 && isWalkable(map, enemy_i, enemy_j + 1)) {
                        // Move right
                        map[enemy_i][enemy_j] = 1;
                        enemy_j += 1;
                        map[enemy_i][enemy_j] = 3;
                    }
                }
            }
        }
    }
}

*/

