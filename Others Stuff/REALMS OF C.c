#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
 * Realms of C: RPG Game
 * Author: Aditya
 *
 * Unified Game Subsystems:
 * - Module 1: Boss Fight Simulator (Combat, Actions, Critical Hits)
 * - Module 2: Loot Table & Farming Analyzer (2D Matrix Calculations)
 * - Module 3: Spell Book Lookup & Validation (Safe String Parsing)
 * - Module 4: Modular Character Engine (Damage, Healing, Level Ups)
 * - Module 5: Stat Buffs & Equipment Swap (Memory Addresses & Pointers)
 * - Module 6: Game Save & Load System (Profile Struct & File I/O)
 */

/* =========================================================================
 * Data Structures & Function Declarations
 * ========================================================================= */
struct PlayerProfile {
    char name[50];
    int level;
    int currentHp;
    int gold;
    int classType;
};

// Module 4: Character Engine Functions
int calculateDamage(int base, int weapon);
int applyHealing(int currentHp, int healAmount);
int checkLevelUp(int currentXp);

// Module 5: Pointer Functions
void applyBuff(int *hpAddress, int buffAmount);
void swapWeapons(int *player1WeaponId, int *player2WeaponId);

// Module 6: File I/O Functions
void saveGame(const struct PlayerProfile *player, const char *filename);
int loadGame(struct PlayerProfile *player, const char *filename);

// Game Subsystem Runners
int bossFightSimulator();
int lootTableAnalyzer();
int spellBookLookup();
int characterEngine();
int statBuffsAndEquipmentSwap();
int gameSaveAndLoad();

/* =========================================================================
 * Main Game Menu
 * ========================================================================= */
int main() {
    int choice;
    do {
        printf("\n=======================================================\n");
        printf("                  REALMS OF C: RPG GAME                \n");
        printf("=======================================================\n");
        printf("1. Boss Fight Simulator\n");
        printf("2. Loot Table & Farming Analyzer\n");
        printf("3. Spell Book Lookup & Validation\n");
        printf("4. Modular Character Engine\n");
        printf("5. Stat Buffs & Equipment Swap\n");
        printf("6. Game Save & Load System\n");
        printf("7. Exit Game\n");
        printf("=======================================================\n");
        printf("Enter Choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                bossFightSimulator();
                break;
            case 2:
                lootTableAnalyzer();
                break;
            case 3:
                spellBookLookup();
                break;
            case 4:
                characterEngine();
                break;
            case 5:
                statBuffsAndEquipmentSwap();
                break;
            case 6:
                gameSaveAndLoad();
                break;
            case 7:
                printf("\nExiting Game. Goodbye!\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

/* =========================================================================
 * Module 1: Boss Fight Simulator (Operators & Control Flow)
 * ========================================================================= */
int bossFightSimulator() {
    srand(time(NULL));
    int playerHealth = 100;
    int bossHealth   = 150;
    int coins        = 100;
    int healthPotion = 0;
    int luckPotion   = 1;
    int attackDamage = 25;
    int choice;
    int action;
    double damage;
    int status = 0;

    while (1) {
        printf("\n============================\n");
        printf("     BOSS FIGHT SIMULATOR\n");
        printf("============================\n");
        printf("1. Play Game\n");
        printf("2. Player Info\n");
        printf("3. Return to Game Menu\n");
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid text input! Please enter a number.\n");
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\nPreparing Battle");
                for (int i = 0; i < 5; i++) {
                    sleep(1);
                    printf(".");
                    fflush(stdout);
                }
                printf("\nBattle Started!\n");

                while (playerHealth > 0 && bossHealth > 0) {
                    printf("\n============================\n");
                    printf("Player Health : %d\n", playerHealth);
                    printf("Boss Health   : %d\n", bossHealth);
                    printf("Coins         : %d\n", coins);
                    printf("Health Potion : %d\n", healthPotion);
                    printf("============================\n");

                    if (luckPotion > 0) {
                        double luckMultiplier = (rand() % 51) / 100.0;
                        damage = attackDamage + (attackDamage * luckMultiplier);
                        luckPotion--;
                        printf("\nLuck Potion Activated!\n");
                    } else {
                        damage = attackDamage;
                    }

                    bossHealth -= (int)damage;
                    printf("You dealt %.2lf damage!\n", damage);

                    if (damage >= 35.0) {
                        printf("ULTRA CRITICAL HIT!\n");
                    } else if (damage >= 30.0) {
                        printf("SUPER CRITICAL HIT!\n");
                    } else {
                        printf("NORMAL HIT!\n");
                    }

                    if (bossHealth <= 0) {
                        break;
                    }

                    do {
                        printf("\nChoose Action\n");
                        printf("1. Defend\n");
                        printf("2. Buy Health Potion (50 Coins)\n");
                        printf("3. Use Health Potion\n");
                        printf("4. Skip Turn\n");
                        printf("Enter Choice: ");

                        if (scanf("%d", &action) != 1) {
                            while (getchar() != '\n');
                            action = 0;
                            continue;
                        }
                        while (getchar() != '\n');
                        system("cls");
                    } while (action < 1 || action > 4);

                    switch (action) {
                        case 1:
                            printf("\nAttempting Defense...\n");
                            if (rand() % 2 == 1) {
                                printf("Defense Successful!\n");
                                status |= 1;
                            } else {
                                printf("Defense Failed!\n");
                            }
                            break;
                        case 2:
                            if (coins >= 50) {
                                coins -= 50;
                                healthPotion++;
                                printf("Purchased 1 Health Potion!\n");
                            } else {
                                printf("Not Enough Coins!\n");
                            }
                            break;
                        case 3:
                            if (healthPotion > 0) {
                                playerHealth += 30;
                                healthPotion--;
                                printf("Health Potion Used!\n");
                            } else {
                                printf("No Health Potions Available!\n");
                            }
                            break;
                        case 4:
                            printf("Turn Skipped!\n");
                            break;
                    }

                    if (status & 1) {
                        printf("Boss Attack Blocked!\n");
                        status = 0;
                    } else {
                        playerHealth -= attackDamage;
                        printf("Boss dealt %d damage!\n", attackDamage);
                    }

                    if (playerHealth <= 0) {
                        break;
                    }
                }

                printf("\n============================\n");
                (playerHealth > 0)
                    ? printf("YOU WIN THE BATTLE!\n")
                    : printf("YOU LOST THE BATTLE!\n");
                printf("============================\n");

                playerHealth = 100;
                bossHealth   = 150;
                coins        = 100;
                healthPotion = 0;
                luckPotion   = 1;
                break;

            case 2:
                printf("\n========== PLAYER INFO ==========\n");
                printf("Health        : %d\n", playerHealth);
                printf("Coins         : %d\n", coins);
                printf("Health Potion : %d\n", healthPotion);
                printf("Luck Potion   : %d\n", luckPotion);
                printf("Size of Health Variable : %u Bytes\n", (unsigned int)sizeof(playerHealth));
                printf("=================================\n");
                break;

            case 3:
                printf("Returning to Game Menu...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}

/* =========================================================================
 * Module 2: Loot Table Matrix & Farming Analyzer (2D Arrays)
 * ========================================================================= */
int lootTableAnalyzer() {
    int lootTable[3][4] = {
        {5, 1, 0, 20},
        {3, 2, 1, 50},
        {1, 3, 5, 500}
    };
    const char *enemyNames[3] = {"Goblin", "Orc", "Dragon"};
    int itemValues[3] = {10, 50, 250};
    int bestEnemyIndex = 0;
    int maxGoldValue = 0;

    printf("\n=== Loot Table & Farming Analyzer ===\n\n");
    for (int i = 0; i < 3; i++) {
        int totalValue = 0;
        for (int j = 0; j < 3; j++) {
            totalValue += lootTable[i][j] * itemValues[j];
        }
        totalValue += lootTable[i][3];
        printf("%s Loot Summary:\n", enemyNames[i]);
        printf("  - Common Items: %d (Value: %d)\n", lootTable[i][0], lootTable[i][0] * itemValues[0]);
        printf("  - Rare Items:   %d (Value: %d)\n", lootTable[i][1], lootTable[i][1] * itemValues[1]);
        printf("  - Epic Items:   %d (Value: %d)\n", lootTable[i][2], lootTable[i][2] * itemValues[2]);
        printf("  - Flat Gold:    %d\n", lootTable[i][3]);
        printf("  Total Calculated Value: %d Gold\n\n", totalValue);

        if (totalValue > maxGoldValue) {
            maxGoldValue = totalValue;
            bestEnemyIndex = i;
        }
    }
    printf("---------------------------------------\n");
    printf("Optimal Farming Target: %s (%d Gold equivalent)\n",
           enemyNames[bestEnemyIndex], maxGoldValue);
    printf("---------------------------------------\n");
    return 0;
}

/* =========================================================================
 * Module 3: Spell Book Lookup & Command Validation (String Manipulation)
 * ========================================================================= */
int spellBookLookup() {
    const char *spellBook[3] = {"Fireball", "Heal", "Blizzard"};
    char input[50];
    char historyLog[100] = "None";
    int found = 0;

    printf("\n=== Spell Book Lookup & Validation ===\n");
    printf("Spells Available: [Fireball] [Heal] [Blizzard]\n\n");
    printf("Enter spell to cast: ");

    if (fgets(input, sizeof(input), stdin) != NULL) {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;
        }
        if (len == 0) {
            printf("Error: Spell name cannot be empty!\n");
            return 1;
        }
        for (int i = 0; i < 3; i++) {
            if (strcmp(input, spellBook[i]) == 0) {
                strcpy(historyLog, input);
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Success: You cast %s!\n", input);
            printf("Action History Log updated to: [ %s ]\n", historyLog);
        } else {
            printf("Error: Spell '%s' is unknown!\n", input);
            printf("Action History Log remains: [ %s ]\n", historyLog);
        }
    }
    return 0;
}

/* =========================================================================
 * Module 4: Modular Character Engine (Functions)
 * ========================================================================= */
int calculateDamage(int base, int weapon) {
    return base + weapon;
}

int applyHealing(int currentHp, int healAmount) {
    int updatedHp = currentHp + healAmount;
    if (updatedHp > 100) {
        updatedHp = 100;
    }
    return updatedHp;
}

int checkLevelUp(int currentXp) {
    if (currentXp >= 100) {
        return 2;
    }
    return 1;
}

int characterEngine() {
    int hp = 75;
    int xp = 90;
    int baseDmg = 20;
    int weaponBonus = 15;

    printf("\n=== Modular Character Engine ===\n");
    printf("Starting State: HP = %d, XP = %d, Base Damage = %d, Weapon Bonus = %d\n\n",
           hp, xp, baseDmg, weaponBonus);

    int finalDmg = calculateDamage(baseDmg, weaponBonus);
    printf("Executing Attack:\n");
    printf("  Damage Dealt: %d\n\n", finalDmg);

    printf("Taking Damage: Player hit for 50 damage.\n");
    hp -= 50;
    printf("  HP is now: %d\n", hp);

    printf("Using Potion: Applying 40 HP healing.\n");
    hp = applyHealing(hp, 40);
    printf("  HP is now: %d\n\n", hp);

    printf("Gaining XP: Player gains 15 XP.\n");
    xp += 15;
    int currentLevel = checkLevelUp(xp);
    printf("  Total XP: %d | Level status: Level %d\n", xp, currentLevel);
    return 0;
}

/* =========================================================================
 * Module 5: Stat Buffs & Equipment Swap (Call-by-Reference Pointers)
 * ========================================================================= */
void applyBuff(int *hpAddress, int buffAmount) {
    *hpAddress += buffAmount;
}

void swapWeapons(int *player1WeaponId, int *player2WeaponId) {
    int temp = *player1WeaponId;
    *player1WeaponId = *player2WeaponId;
    *player2WeaponId = temp;
}

int statBuffsAndEquipmentSwap() {
    int playerHp = 80;
    int p1WeaponId = 101;
    int p2WeaponId = 202;

    printf("\n=== Stat Buffs & Equipment Swap (Pointers) ===\n\n");
    printf("Before Operations:\n");
    printf("  Player HP: %d (Stored at address: %p)\n", playerHp, (void*)&playerHp);
    printf("  Player 1 Weapon ID: %d (Stored at address: %p)\n", p1WeaponId, (void*)&p1WeaponId);
    printf("  Player 2 Weapon ID: %d (Stored at address: %p)\n\n", p2WeaponId, (void*)&p2WeaponId);

    printf("Applying +25 HP buff via pointer...\n");
    applyBuff(&playerHp, 25);
    printf("  Updated Player HP: %d\n\n", playerHp);

    printf("Swapping weapon slots between Player 1 and Player 2...\n");
    swapWeapons(&p1WeaponId, &p2WeaponId);
    printf("After Swap:\n");
    printf("  Player 1 Weapon ID: %d\n", p1WeaponId);
    printf("  Player 2 Weapon ID: %d\n", p2WeaponId);
    return 0;
}

/* =========================================================================
 * Module 6: Game Save & Load System (Structures & Files)
 * ========================================================================= */
void saveGame(const struct PlayerProfile *player, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for saving!\n");
        return;
    }
    fprintf(file, "%s,%d,%d,%d,%d\n", player->name, player->level, player->currentHp, player->gold, player->classType);
    fclose(file);
    printf("Game saved successfully to %s\n", filename);
}

int loadGame(struct PlayerProfile *player, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open save file!\n");
        return 0;
    }
    if (fscanf(file, "%49[^,],%d,%d,%d,%d", player->name, &player->level, &player->currentHp, &player->gold, &player->classType) == 5) {
        fclose(file);
        printf("Game loaded successfully from %s\n", filename);
        return 1;
    }
    fclose(file);
    printf("Error: Save file format invalid!\n");
    return 0;
}

int gameSaveAndLoad() {
    const char *saveFileName = "savegame.txt";
    struct PlayerProfile savedPlayer = {
        "Aditya",
        5,
        120,
        350,
        1
    };

    printf("\n=== RPG Game Save & Load System ===\n\n");
    printf("Saving Character Profile:\n");
    printf("  Name       : %s\n", savedPlayer.name);
    printf("  Level      : %d\n", savedPlayer.level);
    printf("  HP         : %d\n", savedPlayer.currentHp);
    printf("  Gold       : %d\n", savedPlayer.gold);
    printf("  Class Type : %d\n\n", savedPlayer.classType);

    saveGame(&savedPlayer, saveFileName);

    struct PlayerProfile loadedPlayer = {0};
    printf("\nLoading Character Profile from File:\n");
    if (loadGame(&loadedPlayer, saveFileName)) {
        printf("  Loaded Name       : %s\n", loadedPlayer.name);
        printf("  Loaded Level      : %d\n", loadedPlayer.level);
        printf("  Loaded HP         : %d\n", loadedPlayer.currentHp);
        printf("  Loaded Gold       : %d\n", loadedPlayer.gold);
        printf("  Loaded Class Type : %d\n", loadedPlayer.classType);
    }
    return 0;
}
