#ifndef DAMAGEABLEOBJECT_HPP
#define DAMAGEABLEOBJECT_HPP

class DamageableObject
{
public:
    DamageableObject(int initialHp);

    void heal(int d);
    void damage(int d);
    bool isDead();
    int getHitpoints();

protected:
    bool isAlive;
    int  hp;
};

#endif //DAMAGEABLEOBJECT_HPP
