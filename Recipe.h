#ifndef RECIPE_H_INCLUDED
#define RECIPE_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
class Recipe
{
public:

    Recipe();
    Recipe(string Type, string NameOfRecipe, string Ingredients, string PreparationSteps,
        int CookingTime);
    Recipe(const Recipe& recipe);
    void setType(string Type);
    void setNameOfRecipe(string NameOfRecipe);
    void setIngredients(string Ingredients);
    void setPreparationSteps(string PreparationSteps);
    void setCookingTime(int CookingTime);

    string getType()const;
    string getNameOfRecipe()const;
    string getIngredients()const;
    string getPreparationSteps()const;
    int getCookingTime()const;
    void display()const;
    bool operator <(const Recipe& recipe)const;
    bool operator >(const Recipe& recipe)const;
    bool operator ==(const Recipe& recipe)const;



protected:
    string type;
    string nameOfRecipe;
    string ingredients;
    string preparationSteps;
    int cookingTime;

};
#endif





