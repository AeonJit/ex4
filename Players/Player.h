//
// Created by Amit and Tal on 1/12/2022.
//
#ifndef EX4_Player_H
#define EX4_Player_H

#include <string>
#include "../utilities.h"

class Player {

  public:

    /*
     * C'tor of Player class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @param
     * @param 
     * @param
     * @param
     * @return
     *      A new instance of Player.
     */
   Player(const std::string name, int maxHP = INITIAL_MAX_HP, int force = INITIAL_FORCE, 
   int level = 1, int coins = 10, int HP = INITIAL_MAX_HP);

  /*
    * Copy C'tor of Player class
    *Not needed, unless copy constructor is not supposed to have same name
    //TODO: FIGURE THIS SHIT OUT
   */
   Player(const Player & player) = default;

  /*
    * D'tor of Player class
    *Not needed, unless copy constructor is not supposed to have same name
    //TODO: FIGURE THIS SHIT OUT
   */
    virtual ~Player() = default;

  /*
   * Assigment Operator of Player class.
   *take data from an existing object to another existing object.
   */
   Player & operator = (const Player & player ) = default;

  /*
   * @brief
      Levels up the invoker if possible.
   *
   * @return
   *      true, if below lvl 10. False if lvl 10.
  */
   void levelUp();

   /*
   * @brief
      Get Player name.
   *
   * @return
   *      Player name.
  */
   std::string getName() const; 

  /*
   * @brief 
      retures the invoker's lvl.
   * @return
   *      int Player's lvl.
  */

   int getLevel() const;

  /*
   *@brief 
      adding to the invoker's force.
      @param
      amount to be added.
   * @return
      void
  */
   void buff(int amount);

   /*
   *@brief 
      decreasing to the invoker's force.
      @param
      amount to be decreased.
   * @return
      void
  */ 

   void weaken(int amount);

  /*
     *@brief 
        Heals the invoker by the argument's amount. Cannot surpass maxHP.
        @param
        amount to be healed.
     * @return
        void
    */
  virtual void heal(int amount);

  /*
     *@brief 
        damaging the invker by the argument's amount. Cannot go below 0 HP.
        @param
        amount to be damaged.
     * @return
        void
    */
   void damage(int amount);

  /*
     * @brief 
        Checks if the invoker is dead.
     * @return
     *      bool If player is knocked out true else false.
    */

   bool isKnockedOut() const;

  /*
   *@brief 
      Adding argument's worth of gold coins to the player.
      @param
      amount to be added.
   * @return
      void
  */
    virtual void addCoins(int amount);

  /*
     * @brief 
        Attempts to pay argument's worth of gold coins from the invoker.
     * @return
     *      bool If player has enough money to make payment true, else false.
    */

   bool pay(int amount);

  /*
   * @brief 
      Returns the invoker's strength. Strength is defined as (force+level)
   * @return
   *      int Invoker's strength.
  */

  virtual int getAttackStrength() const ;

  virtual std::string getJob() const = 0;

  friend std::ostream& operator<<(std::ostream& os, const Player& Player);

  static const int INITIAL_MAX_HP = 100;

   protected: 

     std::string m_name;
   int m_maxHP;
   int m_force;
   int m_level;
   int m_coins;
   int m_HP;


   static const int INITIAL_FORCE = 5;
   static const int MAX_LEVEL = 10;
   static const int STARTING_LEVEL = 1;
   static const int STARTING_COINS = 0;
   static const int MULTIPLY_FACTOR = 2;

   
      std::string m_name;
   int m_maxHP;
   int m_force;
   int m_level;
   int m_coins;
   int m_HP;

};



#endif //EX4_Player_H