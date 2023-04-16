#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <string.h>
#include "Recipe.h"
using namespace std;
Recipe::Recipe() {}
Recipe::Recipe(string Type, string NameOfRecipe, string Ingredients, string PreparationSteps,
    int CookingTime)
{
    setType(Type);
    setNameOfRecipe(NameOfRecipe);
    setIngredients(Ingredients);
    setPreparationSteps(PreparationSteps);
    setCookingTime(CookingTime);
}
Recipe::Recipe(const Recipe& recipe)
{
    this->type = recipe.type;
    this->nameOfRecipe = recipe.nameOfRecipe;
    this->ingredients = recipe.ingredients;
    this->preparationSteps = recipe.preparationSteps;
    this->cookingTime = recipe.cookingTime;
}
void Recipe::setType(string Type)
{
    this->type = Type;
}
void Recipe::setNameOfRecipe(string NameOfRecipe)
{
    this->nameOfRecipe = NameOfRecipe;
}
void Recipe::setIngredients(string Ingredients)
{
    this->ingredients = Ingredients;
}
void Recipe::setPreparationSteps(string PreparationSteps)
{
    this->preparationSteps = PreparationSteps;
}
void Recipe::setCookingTime(int CookingTime)
{
    this->cookingTime = CookingTime;
}
string Recipe::getType()const
{
    return this->type;
}
string Recipe::getNameOfRecipe()const
{
    return this->nameOfRecipe;
}

string Recipe::getIngredients()const
{
    return this->ingredients;
}

string Recipe::getPreparationSteps()const
{
    return this->preparationSteps;
}
int Recipe::getCookingTime()const
{
    return this->cookingTime;
}

bool Recipe::operator<(const Recipe& recipe)const
{
    return this->nameOfRecipe < recipe.nameOfRecipe;
}

bool Recipe::operator>(const Recipe& recipe)const
{
    return this->nameOfRecipe > recipe.nameOfRecipe;
}
bool Recipe::operator==(const Recipe& recipe)const
{
    return this->nameOfRecipe == recipe.nameOfRecipe;
}
void Recipe::display()const
{
    cout << "Type" << type << endl;
    cout << "Name Of Recipe" << nameOfRecipe << endl;
    cout << "Ingredients" << ingredients << endl;
    cout << "PreparationSteps" << preparationSteps << endl;
    cout << "CookingTime" << cookingTime << endl;
}


