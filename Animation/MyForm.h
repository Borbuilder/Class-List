#pragma once
#include<string>
#include<vector>
#include "../List/List/TPolinom.h"
#include "../List/List/Monom.h"
#include<msclr\marshal_cppstd.h>
#include<exception>

std::vector<TPolinom> p_vector;
//�����, ������������, �������� �� ������ ������� ��� ������
int label4_flag = 0; //1 ������
int label5_flag = 0; //2 ������
int label6_flag = 0; //3 ������
int label7_flag = 0; //4 ������
int label8_flag = 0; //5 ������
int label14_flag = 0;

int first_input_flag = 0;
int button2_flag = 0;

namespace Animation {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;


	protected:
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->MinimumSize = System::Drawing::Size(2, 100);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(428, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(12, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(428, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(467, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(107, 20);
			this->button1->TabIndex = 2;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(467, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 20);
			this->button2->TabIndex = 3;
			this->button2->Text = L"��������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(467, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 20);
			this->button3->TabIndex = 4;
			this->button3->Text = L"���������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"��������:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(136, 47);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(43, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 125);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"���������:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Location = System::Drawing::Point(136, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(432, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Snow;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Location = System::Drawing::Point(136, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(432, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label4";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Snow;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label5->Location = System::Drawing::Point(136, 190);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(432, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"label5";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Snow;
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label6->Location = System::Drawing::Point(136, 210);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(432, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"label6";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::Color::Snow;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label7->Location = System::Drawing::Point(136, 230);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(432, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"label7";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::Color::Snow;
			this->label8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label8->Location = System::Drawing::Point(136, 250);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(432, 20);
			this->label8->TabIndex = 13;
			this->label8->Text = L"label8";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::Snow;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label9->Location = System::Drawing::Point(12, 250);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(100, 20);
			this->label9->TabIndex = 18;
			this->label9->Text = L"label9";
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::label9_Click);
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::Color::Snow;
			this->label10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label10->Location = System::Drawing::Point(12, 230);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 20);
			this->label10->TabIndex = 17;
			this->label10->Text = L"label10";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::Color::Snow;
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Location = System::Drawing::Point(12, 210);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(100, 20);
			this->label11->TabIndex = 16;
			this->label11->Text = L"label11";
			this->label11->Click += gcnew System::EventHandler(this, &MyForm::label11_Click);
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::Color::Snow;
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Location = System::Drawing::Point(12, 190);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(100, 20);
			this->label12->TabIndex = 15;
			this->label12->Text = L"label12";
			this->label12->Click += gcnew System::EventHandler(this, &MyForm::label12_Click);
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::Snow;
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Location = System::Drawing::Point(12, 170);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(100, 20);
			this->label13->TabIndex = 14;
			this->label13->Text = L"label13";
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click);
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::Snow;
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label14->Location = System::Drawing::Point(136, 270);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(432, 20);
			this->label14->TabIndex = 19;
			this->label14->Text = L"label14";
			this->label14->Click += gcnew System::EventHandler(this, &MyForm::label14_Click);
			// 
			// label15
			// 
			this->label15->BackColor = System::Drawing::Color::Snow;
			this->label15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label15->Location = System::Drawing::Point(12, 270);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(100, 20);
			this->label15->TabIndex = 20;
			this->label15->Text = L"label15";
			this->label15->Click += gcnew System::EventHandler(this, &MyForm::label15_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Linen;
			this->ClientSize = System::Drawing::Size(598, 549);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//���� ��� ����� �������� 1
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//���� ��� ����� �������� 2
	}
	/*private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//���������� ��� 1 ����

		std::string input_str1;
		input_str1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
		TPolinom polinom1;
		polinom1.createPolinom(input_str1);
		p_vector.push_back(polinom1);

		//���������� � �������,��� 6 �����, ���� ��������� ������, ��� �����, �� ��� ��������� �������� ���������� � 6 ������
		if (label4_flag == 0)
		{
			label4->Text = textBox1->Text;
			label4_flag = 1;
			label9->Text = "1";
		}
		else if (label5_flag == 0)
		{
			label5->Text = textBox1->Text;
			label5_flag = 1;
			label10->Text = "2";
		}
		if (label6_flag == 0)
		{
			label6->Text = textBox1->Text;
			label6_flag = 1;
			label11->Text = "3";
		}
		else if (label7_flag == 0)
		{
			label7->Text = textBox1->Text;
			label7_flag = 1;
			label10->Text = "4";
		}
		else if (label8_flag == 0)
		{
			label8->Text = textBox1->Text;
			label8_flag = 1;
			label9->Text = "5";
		}
		else 
		{
			label14->Text = textBox1->Text;
			label14_flag = 1;
			label15->Text = "6";
		}
	}*/
	/*private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//���������� ��� 2 ����

		std::string input_str2;
		input_str2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
		TPolinom polinom2;
		polinom2.createPolinom(input_str2);
		p_vector.push_back(polinom2);


		//���������� � �������,��� 6 �����, ���� ��������� ������, ��� �����, �� ��� ��������� �������� ���������� � 6 ������
	    if (label4_flag == 0)
		{
			label4->Text = textBox1->Text;
			label4_flag = 1;
			label9->Text = "1";
		}
		else if (label5_flag == 0)
		{
			label5->Text = textBox1->Text;
			label5_flag = 1;
			label10->Text = "2";
		}
		if (label6_flag == 0)
		{
			label6->Text = textBox1->Text;
			label6_flag = 1;
			label11->Text = "3";
		}
		else if (label7_flag == 0)
		{
			label7->Text = textBox1->Text;
			label7_flag = 1;
			label10->Text = "4";
		}
		else if (label8_flag == 0)
		{
			label8->Text = textBox1->Text;
			label8_flag = 1;
			label9->Text = "5";
		}
		else
		{
			label14->Text = textBox1->Text;
			label14_flag = 1;
			label15->Text = "6";
		}
	}*/
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	   //���������
		
		std::string input_str1;
		input_str1 = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string input_str2;
		input_str2 = msclr::interop::marshal_as<std::string>(textBox2->Text);
	
		if (
			(input_str1 != "1" || input_str1 != "2" || input_str1 != "3" || input_str1 != "4" || input_str1 != "5" || input_str1 != "6")
			&&
			(input_str2 != "1" || input_str2 != "2" || input_str2 != "3" || input_str2 != "4" || input_str2 != "5" || input_str2 != "6")
			)
		{
			TPolinom polinom1;
			polinom1.createPolinom(input_str1);
			p_vector.push_back(polinom1);
			addToTable(input_str1);
			TPolinom polinom2;
			polinom2.createPolinom(input_str2);
			p_vector.push_back(polinom2);
			addToTable(input_str2);
			first_input_flag = 1;
		}
		else {
			std::string op;
			op = msclr::interop::marshal_as<std::string>(textBox3->Text);
			char operation = op[0];
			if (operation == '+' || operation == '-' || operation == '*')
			{
				int table_number1; int table_number2;
				table_number1 = getTableNumber(input_str1);
				table_number2 = getTableNumber(input_str2);

				switch (operation)
				{
				case '+':
					if (first_input_flag == 0)
					{
						TPolinom res;
						res = p_vector[p_vector.size() - 1] + p_vector[p_vector.size() - 2];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
					else {
						TPolinom res;
						res = p_vector[table_number1 - 1] + p_vector[table_number2 - 1];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
				case '-':
					if (first_input_flag == 0)
					{
						TPolinom res;
						res = p_vector[p_vector.size() - 1] - p_vector[p_vector.size() - 2];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
					else {
						TPolinom res;
						res = p_vector[table_number1 - 1] - p_vector[table_number2 - 1];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
				case '*':
					if (first_input_flag == 0)
					{
						TPolinom res;
						res = p_vector[p_vector.size() - 1] * p_vector[p_vector.size() - 2];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
					else {
						TPolinom res;
						res = p_vector[table_number1 - 1] * p_vector[table_number2 - 1];
						p_vector.push_back(res);
						addToTable(res.polinomToString());
					}
				default:
					break;
				}

				//����� �������� ����������
				String^ strange_str = gcnew String(p_vector[p_vector.size() - 1].polinomToString().c_str());
				label3->Text = strange_str;
			}
			else {
				throw std::exception();
			}
		}
    }
    private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	   //��������
    }
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }


    //�������
    private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	  //1 ������� 
    }
    private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	//2 �������
    }
    private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	//3 �������
    }
    private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	//4 �������
    }
    private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	// 5 �������
    }
    private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
	// 6 �������
    }
    private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
	//1 ������� �����
    }
    private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	//2 ������� �����
    }
    private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
	//3 ������� �����
    }
    private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	//4 ������� �����
    }
    private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	//5 ������� �����
    }
	private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
    //6 ������� �����
	}
	void addToTable(const std::string& str)
    {
		String^ strange_str = gcnew String(str.c_str());
			   //���������� � �������,��� 6 �����, ���� ��������� ������, ��� �����, �� ��� ��������� �������� ���������� � 6 ������
			   if (label4_flag == 0)
			   {
				   label4->Text = strange_str;
				   label4_flag = 1;
				   label13->Text = "1";
			   }
			   else if (label5_flag == 0)
			   {
				   label5->Text = strange_str;
				   label5_flag = 1;
				   label12->Text = "2";
			   }
			   if (label6_flag == 0)
			   {
				   label6->Text = strange_str;
				   label6_flag = 1;
				   label11->Text = "3";
			   }
			   else if (label7_flag == 0)
			   {
				   label7->Text = strange_str;
				   label7_flag = 1;
				   label10->Text = "4";
			   }
			   else if (label8_flag == 0)
			   {
				   label8->Text = strange_str;
				   label8_flag = 1;
				   label9->Text = "5";
			   }
			   else
			   {
				   label14->Text = strange_str;
				   label14_flag = 1;
				   label15->Text = "6";
			   }
	}
	int getTableNumber(const std::string& _str)
	{
		int result;
		std::string s1 = msclr::interop::marshal_as<std::string>(label13->Text);
		std::string s2 = msclr::interop::marshal_as<std::string>(label12->Text);
		std::string s3 = msclr::interop::marshal_as<std::string>(label11->Text);
		std::string s4 = msclr::interop::marshal_as<std::string>(label10->Text);
		std::string s5 = msclr::interop::marshal_as<std::string>(label9->Text);
		std::string s6 = msclr::interop::marshal_as<std::string>(label15->Text);
		if (_str == s1) return std::stoi(s1);
		if (_str == s2) return std::stoi(s2);
		if (_str == s3) return std::stoi(s3);
		if (_str == s4) return std::stoi(s4);
		if (_str == s5) return std::stoi(s5);
		if (_str == s6) return std::stoi(s6);
	}
    };
}
