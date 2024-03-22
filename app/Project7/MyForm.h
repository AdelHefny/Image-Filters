#pragma once

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ username;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ submit_btn;
	private: System::Windows::Forms::TextBox^ username_input;
	private: System::Windows::Forms::TextBox^ password_input;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->username = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->submit_btn = (gcnew System::Windows::Forms::Button());
			this->username_input = (gcnew System::Windows::Forms::TextBox());
			this->password_input = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// username
			// 
			this->username->AutoSize = true;
			this->username->BackColor = System::Drawing::Color::Transparent;
			this->username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username->ForeColor = System::Drawing::Color::White;
			this->username->Location = System::Drawing::Point(31, 21);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(97, 24);
			this->username->TabIndex = 0;
			this->username->Text = L"Username";
			this->username->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(31, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Passoword";
			// 
			// submit_btn
			// 
			this->submit_btn->BackColor = System::Drawing::Color::Red;
			this->submit_btn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->submit_btn->FlatAppearance->BorderSize = 0;
			this->submit_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->submit_btn->ForeColor = System::Drawing::Color::White;
			this->submit_btn->Location = System::Drawing::Point(35, 116);
			this->submit_btn->Name = L"submit_btn";
			this->submit_btn->Size = System::Drawing::Size(163, 41);
			this->submit_btn->TabIndex = 3;
			this->submit_btn->Text = L"submit";
			this->submit_btn->UseVisualStyleBackColor = false;
			this->submit_btn->Click += gcnew System::EventHandler(this, &MyForm::btn_Click);
			// 
			// username_input
			// 
			this->username_input->Location = System::Drawing::Point(164, 21);
			this->username_input->Name = L"username_input";
			this->username_input->Size = System::Drawing::Size(100, 20);
			this->username_input->TabIndex = 4;
			// 
			// password_input
			// 
			this->password_input->Location = System::Drawing::Point(164, 62);
			this->password_input->Name = L"password_input";
			this->password_input->Size = System::Drawing::Size(100, 20);
			this->password_input->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(664, 231);
			this->Controls->Add(this->password_input);
			this->Controls->Add(this->username_input);
			this->Controls->Add(this->submit_btn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->username);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Show;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void btn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->username_input->Text = "";
		this->password_input->Text = "";
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
