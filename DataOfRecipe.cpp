#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <fstream>
#include <string.h>
#include <string>
#include <algorithm>
#include "Recipe.h"
#include "DataOfRecipe.h"
using namespace std;

DataOfRecipe::DataOfRecipe() {}
void DataOfRecipe::loadRecipe(string filePath)
{
    ifstream file;

    file.open("RecipeDB.txt", ios::in | ios::app);
    if (!file.is_open()) {
        throw runtime_error("Could not Open File");
        cout << endl;
    }

    else {
        string Type;
        string NameOfRecipe;
        string Ingredients;
        string PreparationSteps;
        int CookingTime;
        file.seekg(0);

        while (getline(file, Type, ',')) {

            getline(file, NameOfRecipe, ',');
            getline(file, Ingredients, ',');

            getline(file, PreparationSteps, ',');
            file >> CookingTime;
            file.ignore();
            Recipe recipe(Type, NameOfRecipe, Ingredients, PreparationSteps, CookingTime);
            this->recipe.push_back(recipe);

        }

        file.close();

    }
}
void DataOfRecipe::addRecipe(Recipe& recipe)
{
    ofstream file;
    file.open("RecipeDB.txt", ios::app);

    if (!file.is_open()) {
        throw runtime_error("Could not Open File");
        cout << endl;
    }
    else {
        file << recipe.getType();
        file << ',';
        file << recipe.getNameOfRecipe();
        file << ',';
        file << recipe.getIngredients();
        file << ',';
        file << recipe.getPreparationSteps();
        file << ',';
        file << recipe.getCookingTime();
        file << '\n';
        this->recipe.push_back(recipe);
        file.close();
        cout << "Recipe Added Successfully" << "\n\n";
    }
}
void DataOfRecipe::saveRecipe(string filePath)
{
    ofstream file("RecipeDB.txt");
    if (!file) {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < recipe.size(); i++)
    {
        file << recipe[i].getType() << recipe[i].getNameOfRecipe() << recipe[i].getIngredients()
            << recipe[i].getPreparationSteps() << recipe[i].getCookingTime();
    }
}
void DataOfRecipe::editRecipe(string updateRecipe, Recipe& r) {

    try {
        //recipe[updateRecipe]=r;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

}
void DataOfRecipe::deleteRecipe(string dummy)
{
    for (int i = 0; i < recipe.size(); i++)
    {
        if (recipe[i].getNameOfRecipe() == dummy)
        {
            recipe.erase(recipe.begin());
        }
    }


}
void DataOfRecipe::displayAllRecipe()
{
    for (int i = 0; i < recipe.size(); i++)
    {
        cout << "========================\n";
        cout << "\nRecipe " << i + 1 << endl;
        recipe[i].display();
    }
}
void DataOfRecipe::sortByName()
{
    sort(recipe.begin(), recipe.end());
}
Recipe& DataOfRecipe::searchRecipeByName(string nameOfRecipe)
{


    for (int i = 0; i < recipe.size(); i++)
    {
        if (recipe[i].getNameOfRecipe() == nameOfRecipe) {
            return recipe[i];
        }
        else
        {
            throw runtime_error("Recipe not found");
        }
    }


}



