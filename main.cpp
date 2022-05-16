//
// Created by florian on 12/05/2022.
//
#include <QMutex>
#include <QThread>
#include <iostream>

#define NUMBEROFTHREADS 5
static QMutex mutex;

class Fourchette
{
private:
    bool isUsed;

public:
    Fourchette()
    {
        this->isUsed = false;
    }
    void set_isUsed(bool arg)
    {
        isUsed = arg;
    };
    bool get_isUsed()
    {
        return isUsed;
    }
};

class Philosophe : public QThread
{
private:
    int tid;
    bool wantToEat;
    bool wantToThink;
    Fourchette *fourchetteGauche;
    Fourchette *fourchetteDroite;
    void run()
    {
        while (1)
        {
            if (this->get_wantToThink())
            {
                this->thinking();
            }
            if (this->get_wantToEat())
            {
                // Code pour récupérer les ressources nécessaires
                if (fourchetteGauche->get_isUsed())
                {
                    std::cout << "Philosophe" << tid << ": "
                              << "La fourchette de gauche  non disponible" << std::endl;
                    this->set_wantToThink(true);
                }
                else if (!(fourchetteDroite->get_isUsed()))
                {
                    mutex.lock();
                    this->eating();
                    mutex.unlock();
                }
                else
                {
                    std::cout << "Philosophe" << tid << ": "
                              << "La fourchette de gauche est disponible mais celle de droite est non disponible" << std::endl;
                    this->set_wantToThink(true);
                }

                if (fourchetteDroite->get_isUsed())
                {
                    std::cout << "Philosophe" << tid << ": "
                              << "La fourchette de droite non disponible" << std::endl;
                    this->set_wantToThink(true);
                }
                else if (!(fourchetteGauche->get_isUsed()))
                {
                    mutex.lock();
                    this->eating();
                    mutex.unlock();
                }
                else
                {
                    std::cout << "Philosophe " << tid << ": "
                              << "La fourchette de droite est disponible mais celle de droite est non disponible" << std::endl;
                    this->set_wantToThink(true);
                }
            }
        }
    };

public:
    void eating()
    {
        if (!(this->fourchetteGauche->get_isUsed()) && !(this->fourchetteDroite->get_isUsed()))
        {
            this->fourchetteGauche->set_isUsed(true);
            this->fourchetteDroite->set_isUsed(true);
            std::cout << "Philosophe " << tid << ": "
                      << "Je mange" << std::endl;
            sleep((int)((float)3 * rand() / (RAND_MAX + 1.0)));
            this->fourchetteGauche->set_isUsed(false);
            this->fourchetteDroite->set_isUsed(false);
        }
        else
        {
            sleep((int)((float)3 * rand() / (RAND_MAX + 1.0)));
        }

        this->set_wantToThink(true);
        return;
    }

    void thinking()
    {
        std::cout << "Philosophe " << tid << ": "
                  << "Je pense" << std::endl;
        sleep((int)((float)3 * rand() / (RAND_MAX + 1.0)));
        this->set_wantToEat(true);
        return;
    }
    void set_wantToEat(bool arg)
    {
        wantToEat = arg;
    };
    void set_wantToThink(bool arg)
    {
        wantToThink = arg;
    };
    bool get_wantToEat()
    {
        return wantToEat;
    };
    bool get_wantToThink()
    {
        return wantToThink;
    };

    Philosophe(int id, Fourchette *g, Fourchette *d) : QThread(), tid(id), fourchetteGauche(g), fourchetteDroite(d)
    {
        this->wantToThink = false;
        this->wantToEat = true;
    };
};

int main(void)
{
    int i;
    QThread *threads[NUMBEROFTHREADS];
    Fourchette fourchettes[NUMBEROFTHREADS];

    for (i = 0; i < NUMBEROFTHREADS; i++)
    {
        if (i < NUMBEROFTHREADS - 1)
        {
            threads[i] = new Philosophe(i, &fourchettes[i], &fourchettes[i + 1]);
            threads[i]->start();
        }
        else
        {
            threads[i] = new Philosophe(i, &fourchettes[i], &fourchettes[0]);
            threads[i]->start();
        }
    }
    for (i = 0; i < NUMBEROFTHREADS; i++)
    {
        threads[i]->wait();
    }

    return 0;
}