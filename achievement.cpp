#define NUMLEADER 40

#define SCORE_UNKNOWN (-1)
#define NO_SCORE_YET (-2)

int currentscore[NUMLEADER];

const char* leadernames[NUMLEADER] = {
  "Score", "Diamonds", "Gold", "Spice", "Rubies", "Elixirs",
  "Shards", "Totems", "Daisies", "Statues", "Feathers", "Sapphires",
  "Hyperstones", "Time to Win-71", "Turns to Win-71",
  "Time to 10 Hyperstones-73", "Turns to 10 Hyperstones-73", "Orbs of Yendor",
  "Fern Flowers", 
  "Royal Jellies", "Powerstones", "Silver", "Wine", "Emeralds", "Grimoires",
  "Holy Grails", "Red Gems", "Pirate Treasures",
  "Shmup Score", "Shmup Time to Win", "Shmup Knife to Win",
  "Bomberbird Eggs", // 31
  "Ambers", // 32
  "Pearls", // 33
  "Hypersian Rugs", // 34
  "Garnets", // 35
  "Princess Challenge", // 36
  "Ivory Figurines", // 37
  "Elemental Gems", // 38
  "Onyxes" // 39
  };

bool haveLeaderboard(int id);

void upload_score(int id, int v);

string achievementMessage[3];
int achievementTimer;
// vector<string> achievementsReceived;

void achievement_log(const char* s, bool euclideanAchievement, bool shmupAchievement) {
  if(cheater) return;
  if(euclid != euclideanAchievement) return;
  if(shmup::on != shmupAchievement) return;
  if(randomPatternsMode) return;
  
  for(int i=0; i<size(achievementsReceived); i++)
    if(achievementsReceived[i] == s) return;
  achievementsReceived.push_back(s);

#ifndef ANDROID
  FILE *f = fopen(scorefile, "at");
  if(!f) return;
  int t = time(NULL) - timerstart;

  time_t timer = time(NULL);
  char buf[128]; strftime(buf, 128, "%c", localtime(&timer));

  fprintf(f, "ACHIEVEMENT %s turns: %d time: %d at: %d c: %d date: %s\n",
    s, turncount, t, int(timerstart), achievement_certify(s, turncount, t, timerstart), buf);

  fclose(f);
#endif
  }

#ifdef STEAM
void improveItemScores();
#include "hypersteam.cpp"
#else
#ifndef ANDROID
void achievement_init() {}
void achievement_close() {}
void achievement_gain(const char* s, bool euclideanAchievement, bool shmupAchievement) {
  achievement_log(s, euclideanAchievement, shmupAchievement);
  }
#endif
#endif

void achievement_collection(eItem it, int prevgold, int newgold) {
  if(cheater) return;
  if(randomPatternsMode) return;
  int q = items[it];

  if(q == 1) {
    if(it == itDiamond) achievement_gain("DIAMOND1");
    if(it == itRuby) achievement_gain("RUBY1");
    if(it == itHyperstone) achievement_gain("HYPER1");
    if(it == itGold) achievement_gain("GOLD1");
    if(it == itStatue) achievement_gain("STATUE1");
    if(it == itShard) achievement_gain("MIRROR1");
    if(it == itBone) achievement_gain("TOTEM1");
    if(it == itSpice) achievement_gain("SPICE1");
    if(it == itElixir) achievement_gain("ELIXIR1");
    if(it == itHell) achievement_gain("DAISY1");
    if(it == itFeather) achievement_gain("FEATHER1");
    if(it == itSapphire) achievement_gain("SAPPHIRE1");
    if(it == itFernFlower) achievement_gain("FERN1");
    if(it == itRoyalJelly) achievement_gain("JELLY1");
    if(it == itWine) achievement_gain("WINE1");
    if(it == itPower) achievement_gain("POWER1");
    if(it == itEmerald) achievement_gain("EMERALD1");
    if(it == itSilver) achievement_gain("SILVER1");
    if(it == itGrimoire) achievement_gain("GRIMOIRE1");
    if(it == itRedGem) achievement_gain("REDGEM1");
    if(it == itPirate) achievement_gain("PIRATE1");
    if(it == itCoast) achievement_gain("COAST1");
    // if(it == itWhirlpool) achievement_gain("WHIRL1");
    if(it == itBombEgg) achievement_gain("MINE1");
    if(it == itPalace) achievement_gain("RUG1");
    if(it == itFjord) achievement_gain("GARNET1");

    if(it == itEdge) achievement_gain("TOWER1");
    if(it == itElemental) achievement_gain("ELEMENT1");
    if(it == itZebra) achievement_gain("ZEBRA1");
    }

  // 32
  if(it == itHolyGrail) {
    if(q == 1) achievement_gain("GRAIL2");
    if(q == 3) achievement_gain("GRAIL3");
    if(q == 8) achievement_gain("GRAIL4");
    }
  
  if(q == 10) {
    if(it == itDiamond) achievement_gain("DIAMOND2");
    if(it == itRuby) achievement_gain("RUBY2");
    if(it == itHyperstone) achievement_gain("HYPER2");
    if(it == itGold) achievement_gain("GOLD2");
    if(it == itStatue) achievement_gain("STATUE2");
    if(it == itShard) achievement_gain("MIRROR2");
    if(it == itBone) achievement_gain("TOTEM2");
    if(it == itSpice) achievement_gain("SPICE2");
    if(it == itElixir) achievement_gain("ELIXIR2");
    if(it == itHell) achievement_gain("DAISY2");
    if(it == itFeather) achievement_gain("FEATHER2");
    if(it == itSapphire) achievement_gain("SAPPHIRE2");
    if(it == itFernFlower) achievement_gain("FERN2");
    if(it == itRoyalJelly) achievement_gain("JELLY2");
    if(it == itWine) achievement_gain("WINE2");
    if(it == itPower) achievement_gain("POWER2");
    if(it == itEmerald) achievement_gain("EMERALD2");
    if(it == itSilver) achievement_gain("SILVER2");
    if(it == itGrimoire) achievement_gain("GRIMOIRE2");
    if(it == itRedGem) achievement_gain("REDGEM2");
    if(it == itPirate) achievement_gain("PIRATE2");
    if(it == itCoast) achievement_gain("COAST2");
    if(it == itWhirlpool) achievement_gain("WHIRL2");
    if(it == itBombEgg) achievement_gain("MINE2");
    if(it == itPalace) achievement_gain("RUG2");
    if(it == itFjord) achievement_gain("GARNET2");

    if(it == itEdge) achievement_gain("TOWER2");
    if(it == itElemental) achievement_gain("ELEMENT2");
    if(it == itZebra) achievement_gain("ZEBRA2");
    }

  if(q == 25) {
    if(it == itDiamond) achievement_gain("DIAMOND3");
    if(it == itRuby) achievement_gain("RUBY3");
    if(it == itHyperstone) achievement_gain("HYPER3");
    if(it == itGold) achievement_gain("GOLD3");
    if(it == itStatue) achievement_gain("STATUE3");
    if(it == itShard) achievement_gain("MIRROR3");
    if(it == itBone) achievement_gain("TOTEM3");
    if(it == itSpice) achievement_gain("SPICE3");
    if(it == itElixir) achievement_gain("ELIXIR3");
    if(it == itHell) achievement_gain("DAISY3");
    if(it == itFeather) achievement_gain("FEATHER3");
    if(it == itSapphire) achievement_gain("SAPPHIRE3");
    if(it == itFernFlower) achievement_gain("FERN3");
    if(it == itRoyalJelly) achievement_gain("JELLY3");
    if(it == itWine) achievement_gain("WINE3");
    if(it == itPower) achievement_gain("POWER3");
    if(it == itEmerald) achievement_gain("EMERALD3");
    if(it == itSilver) achievement_gain("SILVER3");
    if(it == itGrimoire) achievement_gain("GRIMOIRE3");
    if(it == itRedGem) achievement_gain("REDGEM3");
    if(it == itPirate) achievement_gain("PIRATE3");
    if(it == itCoast) achievement_gain("COAST3");
    if(it == itWhirlpool) achievement_gain("WHIRL3");
    if(it == itBombEgg) achievement_gain("MINE3");
    if(it == itPalace) achievement_gain("RUG3");
    if(it == itFjord) achievement_gain("GARNET3");

    if(it == itEdge) achievement_gain("TOWER3");
    if(it == itElemental) achievement_gain("ELEMENT3");
    if(it == itZebra) achievement_gain("ZEBRA3");
    }

  if(q == 50) {
    if(it == itDiamond) achievement_gain("DIAMOND4");
    if(it == itRuby) achievement_gain("RUBY4");
    if(it == itHyperstone) achievement_gain("HYPER4");
    if(it == itGold) achievement_gain("GOLD4");
    if(it == itStatue) achievement_gain("STATUE4");
    if(it == itShard) achievement_gain("MIRROR4");
    if(it == itBone) achievement_gain("TOTEM4");
    if(it == itSpice) achievement_gain("SPICE4");
    if(it == itElixir) achievement_gain("ELIXIR4");
    if(it == itHell) achievement_gain("DAISY4");
    if(it == itFeather) achievement_gain("FEATHER4");
    if(it == itSapphire) achievement_gain("SAPPHIRE4");
    if(it == itFernFlower) achievement_gain("FERN4");
    if(it == itRoyalJelly) achievement_gain("JELLY4");
    if(it == itWine) achievement_gain("WINE4");
    if(it == itPower) achievement_gain("POWER4");
    if(it == itEmerald) achievement_gain("EMERALD4");
    if(it == itSilver) achievement_gain("SILVER4");
    if(it == itGrimoire) achievement_gain("GRIMOIRE4");
    if(it == itRedGem) achievement_gain("REDGEM4");
    if(it == itPirate) achievement_gain("PIRATE4");
    if(it == itCoast) achievement_gain("COAST4");
    if(it == itWhirlpool) achievement_gain("WHIRL4");
    if(it == itBombEgg) achievement_gain("MINE4");
    if(it == itPalace) achievement_gain("RUG4");
    if(it == itFjord) achievement_gain("GARNET4");

    if(it == itEdge) achievement_gain("TOWER4");
    if(it == itElemental) achievement_gain("ELEMENT4");
    if(it == itZebra) achievement_gain("ZEBRA4");
    }
  
  if(it == itOrbYendor) {
    achievement_gain("YENDOR2");
    if(pureHardcore()) achievement_gain("HARDCORE");
    if(shmup::on) achievement_gain("SHMUP", false, true);
    }
  }

void achievement_count(const string& s, int current, int prev) {
  if(cheater) return;
  if(shmup::on) return;
  if(randomPatternsMode) return;
  if(s == "GOLEM" && current >= 5)
    achievement_gain("GOLEM2");
  if(s == "GOLEM" && current >= 10)
    achievement_gain("GOLEM3");
  if(s == "STAB" && current >= 1)
    achievement_gain("STABBER1");
  if(s == "STAB" && current >= 2)
    achievement_gain("STABBER2");
  if(s == "STAB" && current >= 4)
    achievement_gain("STABBER3");
  if(s == "MIRRORKILL" && current-prev >= 1)
    achievement_gain("MIRRORKILL1");
  if(s == "MIRRORKILL" && current-prev >= 2)
    achievement_gain("MIRRORKILL2");
  if(s == "MIRRORKILL" && current-prev >= 3)
    achievement_gain("MIRRORKILL3");
  if(s == "FLASH" && current-prev >= 1)
    achievement_gain("FLASH1");
  if(s == "FLASH" && current-prev >= 5)
    achievement_gain("FLASH2");
  if(s == "FLASH" && current-prev >= 10)
    achievement_gain("FLASH3");
  if(s == "LIGHTNING" && current-prev >= 1)
    achievement_gain("LIGHTNING1");
  if(s == "LIGHTNING" && current-prev >= 5)
    achievement_gain("LIGHTNING2");
  if(s == "LIGHTNING" && current-prev >= 10)
    achievement_gain("LIGHTNING3");
  if(s == "MIRAGE" && current >= 35)
    achievement_gain("MIRAGE", true);
  if(s == "ORB" && current >= 10)
    achievement_gain("ORB3");
  if(s == "BUG" && current >= 1000)
    achievement_gain("BUG3");
  }

int specific_improved = 0;
int specific_what = 0;

void improve_score(int i, eItem what) {
#ifdef HAVE_ACHIEVEMENTS
  if(haveLeaderboard(i)) updateHi(what, currentscore[i]);
  if(items[what] && haveLeaderboard(i)) {
    if(items[what] > currentscore[i] && currentscore[i] != SCORE_UNKNOWN) {
      specific_improved++; specific_what = what;
      currentscore[i] = items[what];
      }
      
    upload_score(i, items[what]);
    }
#endif
  }

void achievement_score(int cat, int number) {
#ifdef HAVE_ACHIEVEMENTS
  if(cheater) return;
  if(euclid) return;
  if(randomPatternsMode) return;
  upload_score(cat, number);
#endif
  }

void improveItemScores() {
  for(int i=1; i<=12; i++) improve_score(i, eItem(i));
  improve_score(17, itOrbYendor);
  improve_score(18, itFernFlower);
  improve_score(19, itRoyalJelly);
  improve_score(20, itPower);
  improve_score(21, itSilver);
  improve_score(22, itWine);
  improve_score(23, itEmerald);
  improve_score(24, itGrimoire);
  improve_score(25, itHolyGrail);
  improve_score(26, itRedGem);
  improve_score(27, itPirate);
  improve_score(31, itBombEgg);
  improve_score(32, itCoast);
  improve_score(33, itWhirlpool);
  improve_score(34, itPalace);
  improve_score(35, itFjord);
  
  improve_score(37, itEdge);
  improve_score(38, itElemental);
  improve_score(39, itZebra);
  }

void achievement_final(bool really_final) {
#ifdef HAVE_ACHIEVEMENTS
  if(cheater) return;
  if(euclid) return;
  if(randomPatternsMode) return;
  int total_improved = 0;
  specific_improved = 0;
  specific_what = 0;
  
  if(!shmup::on) improveItemScores(); 
  
  int sid = shmup::on ? 28 : 0;
  
  int tg = gold();
  if(tg && haveLeaderboard(sid)) {
    if(tg > currentscore[sid] && currentscore[sid] != SCORE_UNKNOWN) {
      if(currentscore[sid] < 0) total_improved += 2;
      total_improved++; currentscore[sid] = tg;
      }
    upload_score(sid, tg);
    }
  
  if(total_improved >= 2) {
    addMessage(XLAT("Your total treasure has been recorded in the "LEADERFULL"."));
    addMessage(XLAT("Congratulations!"));
    }
  else if(total_improved && specific_improved >= 2)
    addMessage(XLAT("You have improved your total high score and %1 specific high scores!", its(specific_improved)));
  else if(total_improved && specific_improved)
    addMessage(XLAT("You have improved your total and '%1' high score!", iinf[specific_what].name));
  else if(total_improved)
    addMessage(XLAT("You have improved your total high score on "LEADER". Congratulations!"));
  else if(specific_improved >= 2)
    addMessage(XLAT("You have improved %1 of your specific high scores!", its(specific_improved)));
  else if(specific_improved)
    addMessage(XLAT("You have improved your '%1' high score on "LEADER"!", iinf[specific_what].name));
#endif
  }

void achievement_victory(bool hyper) {
#ifdef HAVE_ACHIEVEMENTS
  if(cheater) return;
  if(euclid) return;
  if(randomPatternsMode) return;
  if(hyper && shmup::on) return;

  int t = savetime + time(NULL) - timerstart;
  
  int ih1 = hyper ? 15 : shmup::on ? 29 : 13;
  int ih2 = hyper ? 16 : shmup::on ? 30 : 14;
  
  int improved = 0;
  if(currentscore[ih1] == NO_SCORE_YET || currentscore[ih2] == NO_SCORE_YET)
    improved += 4;
    
  if(currentscore[ih1] < 0 || currentscore[ih1] > t) {
    improved++; currentscore[ih1] = t;
    }

  if(currentscore[ih2] < 0 || currentscore[ih2] > turncount) {
    improved+=2; currentscore[ih2] = turncount;
    }

  if(hyper)
    addMessage(XLAT("You have collected 10 treasures of each type."));

  if(improved) {
    if(improved >= 4) {
      if(!hyper) addMessage(XLAT("This is your first victory!"));
      addMessage(XLAT("This has been recorded in the " LEADERFULL "."));
      addMessage(XLAT("The faster you get here, the better you are!"));
      }
    else if(improved >= 3) {
      if(shmup::on)
        addMessage(XLAT("You have improved both your real time and knife count. Congratulations!"));
      else 
        addMessage(XLAT("You have improved both your real time and turn count. Congratulations!"));
      }
    else if(improved == 1)
      addMessage(XLAT("You have used less real time than ever before. Congratulations!"));
    else if(improved == 2) {
      if(shmup::on)
        addMessage(XLAT("You have used less knives than ever before. Congratulations!"));
      else
        addMessage(XLAT("You have used less turns than ever before. Congratulations!"));
      }
    }
  
  upload_score(ih1, t);
  upload_score(ih2, turncount);
#endif
  }

void achievement_pump();

void achievement_display() {
#ifdef HAVE_ACHIEVEMENTS
  achievement_pump();
  if(achievementTimer) {
    int col = (ticks - achievementTimer);
    if(col > 5000) { achievementTimer = 0; return; }
    if(col > 2500) col = 5000 - col;
    col /= 10; col *= 0x10101;
    displayfr(vid.xres/2, vid.yres/4, 2, vid.fsize * 2, achievementMessage[0], col & 0xFFFF00, 8);
    displayfr(vid.xres/2, vid.yres/4 + vid.fsize*2, 2, vid.fsize * 2, achievementMessage[1], col, 8);
    displayfr(vid.xres/2, vid.yres/4 + vid.fsize*4, 2, vid.fsize, achievementMessage[2], col, 8);
    }
#endif
  }

