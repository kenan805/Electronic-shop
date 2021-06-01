#pragma once
#include "Database.h"
#include "Stock.h"
#include "Admin.h"
#include "Client.h"
#include "MenuOptions.h"
#include<string>
#include "Refrigerator.h"
#include "Smartwatch.h"

namespace Shop {


	int countReadyDb = 0;

	Database* db = new Database();

	void writingForm(const string& text) {
		for (size_t i = 0, length = text.size(); i < length; i++)
		{
			cout << text[i];

			Sleep(30);
		}
		cout << endl;
	}

	void readyDatabase() {
		db->admins = new DbSet<Admin>();
		Admin* admin = new Admin("admin", "admin");
		db->getAdmins()->add(admin);
		delete admin;

		db->clients = new DbSet<Client>();
		Client* client1 = new Client("Kenan", "553334405");
		Client* client2 = new Client("Revan", "772667878");
		db->clients->add(client1);
		db->clients->add(client2);
		delete client1;
		delete client2;

		db->stockDb = new Stock();
		Category* computer = new Category("Computer");
		Category* phone = new Category("Phone");
		Category* refrigerator = new Category("Refrigerator");
		db->stockDb->categories.push_back(computer);
		db->stockDb->categories.push_back(phone);
		db->stockDb->categories.push_back(refrigerator);

		Notebook* notebook1 = new Notebook(1, "Notebook", "Acer", "RS AP714-51T", "Core i5", 4059.99, 8, 0, 512, "Win 10", false, 10);
		Notebook* notebook2 = new Notebook(1, "Notebook", "Lenovo", "IdeaPad Gaming", "Ryzen 5", 2089.99, 8, 1028, 128, "FreeDOS", false, 15);
		db->stockDb->stock.push_back(notebook1);
		db->stockDb->stock.push_back(notebook2);


		Smartphone* phone1 = new Smartphone(2, "Smartphone", "Iphone", "11", 1689.99, 4, 64, "iOS 13", 1, false, 20);
		Smartphone* phone2 = new Smartphone(2, "Smartphone", "Samsung", "Galaxy S21+ DUAL", 2399.99, 8, 128, "Android 11", 2, true, 15);
		db->stockDb->stock.push_back(phone1);
		db->stockDb->stock.push_back(phone2);

		Refrigerator* ref1 = new Refrigerator(3, "Refrigerator", "Bosch", "KGD86AW304", 2199.99, "White", 619, 110, 2, 10);
		db->stockDb->stock.push_back(ref1);

	}

	void clientSignUp() {
		string fullname, phone_number;
		cout << "Enter fullname: ";
		cin >> fullname;
		cout << "Enter phone number: ";
		cin >> phone_number;
		if (db->clients->isExistsClients(fullname)) {
			writeErrorTxtToFile("Error DB001", __LINE__, __FILE__);
			throw DatabaseException("There is user with this name!", __LINE__, __FILE__);
		}
		else {
			Client* newClient = new Client(fullname, phone_number);
			db->clients->add(newClient);
			writeClientSignUpTxtToFile(fullname);
			color(Green);
			writingForm("Registration completed successfully.");
			Sleep(2000);
			delete newClient;
		}
	}

	void appDisplay() {
		color(Green);
		cout << setw(100) << " __                      __                __      __                                \n";
		cout << setw(100) << "|_  |  _  _ |_  _  _    (_  |_   _   _    |_   __ |__)  _  _   _   _  __  /\\   _   _ \n";
		cout << setw(100) << "|__ | (- (_ |_ |  (_)   __) | ) (_) |_)   |__     |__) (_| /_ (_| |      /--\\ |_) |_)\n";
		cout << setw(100) << "                                    |                                         |   |  \n";
	}

	void menuBack() {
		color(Gray);
		cout << "Press enter to continue";
		cin.ignore();
		cin.get();
	}

	void start();

	void entryCheck(const size_t setwNum) {
		cout << setw(setwNum) << "The entry is checked .";
		for (size_t i = 0; i < 2; i++)
		{
			Sleep(1000);
			cout << ".";
		}
	}

	void adminControl() {
		entryCheck(50);
		color(Green);
		cout << "\n\n" << setw(25); writingForm("You are logged in as an administrator!");
		Sleep(1000);
		while (1)
		{
			Menu m;
			m.set_xy(20, 2);
			int choiceAdmin = m.Gmenu("Show all products", "Show all categories", "Show all clients", "Add product", "Add category", "Delete product", "Delete category", "Update product", "Go main menu");
			if (choiceAdmin == 0) {
				system("cls");
				db->getStock()->showAllProductsDetailInfo();
				menuBack();
			}
			else if (choiceAdmin == 1) {
				system("cls");
				db->getStock()->showAllCategoryNames();
				menuBack();
			}
			else if (choiceAdmin == 2) {
				system("cls");
				db->showAllClients();
				menuBack();
			}
			else if (choiceAdmin == 3) {
				system("cls");
				m.clear_screen(false);
				cout << "Which to category do you want to add?\n";
				int choice2 = m.Gmenu("1)Notebook", "2)Smartphone", "3)Household appliances", "Go back menu");
				m.set_xy(20, 2);
				if (!choice2) {
					Notebook* newNotebook = new Notebook();
					db->getStock()->addProduct(newNotebook);
					delete newNotebook;
				}
				else if (choice2 == 1) {
					Smartphone* newPhone = new Smartphone();
					db->getStock()->addProduct(newPhone);
					delete newPhone;
				}
				else if (choice2 == 2) {
					Refrigerator* newRef = new Refrigerator();
					db->getStock()->addProduct(newRef);
					delete newRef;
				}
				else continue;
			}
			else if (choiceAdmin == 4) {
				system("cls");
				string categoryName;
				cout << "Type the name of the category you want to add: ";
				cin >> categoryName;
				Category* newCategory = new Category(categoryName);
				db->getStock()->addCategory(newCategory);
			}
			else if (choiceAdmin == 5) {
				system("cls");
				db->getStock()->showAllProductPreviewInfo();
				size_t id;
				cout << "Select the name of the product you want to delete: ";
				cin >> id;
				db->getStock()->deleteByIdProductById(id);
			}
			else if (choiceAdmin == 6) {
				system("cls");
				db->getStock()->showAllCategoryNames();
				size_t id;
				cout << "Select the category ID you want to delete: ";
				cin >> id;
				db->getStock()->deleteByIdCategory(id);
			}
			else if (choiceAdmin == 7) {
				system("cls");
				db->getStock()->showAllProductPreviewInfo();
				size_t id;
				cout << "Select the product ID you want to update: ";
				cin >> id;
				db->getStock()->updateProduct(id);
				menuBack();

			}
			else if (choiceAdmin == 8) start();
		}
	}

	void clientControl() {
		system("cls");
		while (1)
		{
			system("cls");
			Menu m;
			m.set_xy(20, 2);
			int choiceClient = m.Gmenu("Client sign in", "Client sign up", "Go back menu");
			if (choiceClient == 0) {
				system("cls");
				string fullname;
				cout << "\n\n" << setw(30) << "Enter fullname: ";
				cin >> fullname;
				if (db->clientLogin(fullname)) {
					entryCheck(36);
					color(Green);
					cout << "\n\n" << setw(15); writingForm("Account login was successful!");					
					Sleep(1000);
					while (1)
					{
						system("cls");
						db->getStock()->showAllProductPreviewInfo();
						m.set_xy(60, 10);
						m.clear_screen(false);
						int choice3 = m.Gmenu("Show detail", "Cart", "Choose products to buy", "Log out");
						switch (choice3)
						{
						case 0: {
							system("cls");
							db->getStock()->showAllProductPreviewInfo();
							size_t id;
							cout << "Enter id: ";
							cin >> id;
							if (db->getStock()->isExistsProducts(id)) {
								system("cls");
								for (auto& i : db->getStock()->stock)
								{
									if (id == i->getId()) i->showProductDetail();
								}
								menuBack();
							}
							else {
								cout << "Product not found!" << endl;
								Sleep(1000);
								continue;
							}
						}
							  break;
						case 1: {
							if (db->getStock()->cartProducts.empty()) {
								system("cls");
								cout << "The cart is empty." << endl;
								menuBack();
							}
							else {
								system("cls");
								cout << "Products in the cart." << endl;
								db->getStock()->showCart();
								m.set_xy(60, 5);
								m.clear_screen(false);
								int choiceCart = m.Gmenu("Buy the in the cart", "Delete the in the cart", "Delete the all in the cart", "Back to menu");
								switch (choiceCart) {
								case 0: {
									while (true)
									{
										system("cls");
										db->getStock()->showCart();
										color(White);
										size_t prodId;
										cout << "Enter product id: ";
										cin >> prodId;
										if (db->getStock()->isExistsProducts(prodId)) {
											cout << "Enter quantity: ";
											size_t quantity;
											cin >> quantity;
											if (quantity <= db->getStock()->getProductById(prodId)->getQuantity() && quantity != 0) {
												db->getStock()->getProductById(prodId)->setQuantity(db->getStock()->getProductById(prodId)->getQuantity() - quantity);
												db->getStock()->deleteProductFromCartById(prodId);
												if (!db->getStock()->getProductById(prodId)->getQuantity()) {
													db->getStock()->stock.remove(db->getStock()->getProductById(prodId));
												}
												if (db->getStock()->cartProducts.size() == 0) {
													color(Aqua);
													writingForm("Your order is complete.Thank you for choosing us.By KenanHome");
													db->getStock()->deleteAllCheckId();
													Sleep(3000);
													break;
												}
											}
											else if (quantity > db->getStock()->getProductById(prodId)->getQuantity()) {
												color(Red);
												writingForm("There aren't as many products in stock as you choose.");
												Sleep(2000);
												break;
											}
											else break;
										}
										else {
											cout << "Product not found!" << endl;
										}
									}
								}
									  break;
								case 1: {
									size_t id;
									cout << "Select the id of the product you want to delete: ";
									cin >> id;
									db->getStock()->deleteProductFromCartById(id);
									db->getStock()->deleteCheckId(id);

								}
									  break;
								case 2: {
									system("cls");
									db->getStock()->deleteAllProductFromCart();
									db->getStock()->deleteAllCheckId();
									Sleep(2000);
								}
									  break;
								default: break;
								}

							}

						}
							  break;
						case 2: {
							system("cls");
							db->getStock()->showAllProductPreviewInfo();
							cout << "Which product do you want to add to the cart? Choise id: ";
							size_t id = 0;
							cin >> id;
							if (db->stockDb->isExistsProducts(id)) {
								if (!db->getStock()->isExistCartCheckId(id)) {
									db->getStock()->addProductToCart(id);
									db->getStock()->addCheckId(id);
									continue;
								}
								else {
									writingForm("This product has already been added.");
									Sleep(2000);
									continue;
								}
							}
							else {
								cout << "Product not found!" << endl;
								break;
							}
						}
							  break;
						case 3: {
							db->getStock()->deleteAllProductFromCart();
							db->getStock()->deleteAllCheckId();
							clientControl();
						}
							  break;
						}
					}

				}
				else {
					entryCheck(36);
					color(Red);
					cout << "\n\n" << setw(15); writingForm("Login to account failed ...!");
					Sleep(2000);
				}
			}
			else if (choiceClient == 1) {
				system("cls");
				clientSignUp();
			}
			else start();

		}
	}

	void start() {
		try
		{
			//Start isleyende hazir admin,guest,product,category birde yaranmasin deye 1defe islesin readyDatabase()
			if (countReadyDb == 0) {
				readyDatabase();
			}
			countReadyDb++;
			while (true)
			{
				system("cls");
				Menu m;
				int choice;
				m.set_xy(54, 6);
				appDisplay();
				m.clear_screen(false);
				choice = m.Gmenu("ADMIN", "GUEST", "EXIT");
				cout << setw(65) << "M A I N   M E N U";

				if (choice == 0)
				{
					system("cls");
					string adminUsername, adminPassword;
					cout << "\n\n" << setw(50) << "Enter admin username: ";
					cin >> adminUsername;
					cout << setw(50) << "Enter admin password: ";
					cin >> adminPassword;
					if (db->adminLogin(adminUsername, adminPassword)) {
						adminControl();
					}
					else {
						entryCheck(50);
						cout << "\n\n" << setw(50) << "\t\tLogin to account failed ...!" << endl;
						Sleep(2000);
						continue;
					}
				}
				else if (choice == 1) {
					system("cls");
					clientControl();
				}
				else {
					system("cls");
					cout << "Good bye...";
					delete db;
					exit(0);
				}
			}
		}
		catch (Exception& ex)
		{
			ex.printErrorMsg();
		}
	}
}