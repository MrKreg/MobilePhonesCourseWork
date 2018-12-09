#pragma once
#include "UnitOfWork.h"
#include "EditCreator.h"
#include "EditFeature.h"
#include "EditOs.h"
#include "EditProcessor.h"
#include "EditShop.h"
#include "EditOffer.h"
#include "EditUser.h"

namespace MobilePhonesCourseWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StuffForm
	/// </summary>
	public ref class StuffForm : public System::Windows::Forms::Form
	{
	public:
		StuffForm(UnitOfWork^ uow)
		{
			InitializeComponent();
			this->uow = uow;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StuffForm()
		{
			if (components)
			{
				delete components;
			}
		}



			 UnitOfWork^ uow;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StuffForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(62)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->dataGridView1->Location = System::Drawing::Point(7, 38);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(601, 252);
			this->dataGridView1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(241, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Table name";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button1->Location = System::Drawing::Point(142, 296);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 37);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &StuffForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->button2->Location = System::Drawing::Point(245, 296);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 37);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Update";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &StuffForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(111)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(96)));
			this->button3->Location = System::Drawing::Point(348, 296);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 37);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Insert";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &StuffForm::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBox1->ForeColor = System::Drawing::Color::White;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &StuffForm::comboBox1_SelectedIndexChanged);
			// 
			// StuffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->ClientSize = System::Drawing::Size(614, 344);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"StuffForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Stuff";
			this->Load += gcnew System::EventHandler(this, &StuffForm::StuffForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void InitCombo()
	{
		comboBox1->Items->Add("Creator");
		comboBox1->Items->Add("Feature");
		comboBox1->Items->Add("OS");
		comboBox1->Items->Add("Processor");
		comboBox1->Items->Add("Shop");
		comboBox1->Items->Add("Offer");
		comboBox1->Items->Add("User");
	}
	private: void InitCreator()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Name");
		table->Columns->Add("Email");
		table->Columns->Add("Owner");
		table->Columns->Add("Country");
		for each (Creator^ item in uow->Creator()->GetAllCreators())
		{
			table->Rows->Add(item->GetId(), item->GetName(), item->GetEmail(), item->GetOwner(), item->GetCountry());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private: void InitFeature()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Name");
		table->Columns->Add("Usage");
		for each (Feature^ item in uow->Feature()->GetAllFeatures())
		{
			table->Rows->Add(item->GetId(), item->GetName(), item->GetUsage());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private: void InitOs()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Name");
		table->Columns->Add("Description");
		table->Columns->Add("Create year");
		for each (OS^ item in uow->Os()->GetAllOs())
		{
			table->Rows->Add(item->GetId(), item->GetName(), item->GetDescription(), item->GetCreateYear());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private: void InitProcessor()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Name");
		table->Columns->Add("Frequency");
		table->Columns->Add("Cores");
		table->Columns->Add("Maker");
		for each (Processor^ item in uow->Processor()->GetAllProcessors())
		{
			table->Rows->Add(item->GetId(), item->GetName(), item->GetFrequency(), item->GetCountOfCores(), item->GetMaker());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private: void InitShop() {
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Name");
		table->Columns->Add("Rating");
		table->Columns->Add("Website");
		for each (Shop^ item in uow->Shop()->GetAllShops())
		{
			table->Rows->Add(item->GetId(), item->GetName(), item->GetRating(), item->GetWebsite());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private: void InitOffer()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("id");
		table->Columns->Add("Phone");
		table->Columns->Add("Shop");
		table->Columns->Add("Price");
		table->Columns->Add("Shipping cost");
		table->Columns->Add("Available");
		for each (ShopHasPhone^ item in uow->ShopHasPhone()->GetAllShopHasPhones())
		{
			table->Rows->Add(item->GetId(), item->GetPhoneName(), item->GetShopName(), item->GetPrice(), item->GetShippingCost(), item->GetAvailable());
		}
		dataGridView1->DataSource = table;
		dataGridView1->Columns[0]->Visible = false;
	}
	private:void InitUser()
	{
		DataTable^ table = gcnew DataTable();
		table->Columns->Add("Username");
		table->Columns->Add("Password");
		for each (User^ item in uow->User()->GetAllUsers())
		{
			table->Rows->Add(item->GetUsername(), item->GetEncodedPassword());
		}
		dataGridView1->DataSource = table;
	}
	private:void CallSelected()
	{
		switch (comboBox1->SelectedIndex)
		{
		case 0:
			InitCreator();
			break;
		case 1:
			InitFeature();
			break;
		case 2:
			InitOs();
			break;
		case 3:
			InitProcessor();
			break;
		case 4:
			InitShop();
			break;
		case 5: 
			InitOffer();
			break;
		case 6:
			InitUser();
			break;
		default:
			InitCreator();
			break;
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ username;
		int id;
		if (comboBox1->SelectedIndex > 5)
		{
			username = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value->ToString();
		}
		else
		{
			id = System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		}
		switch (comboBox1->SelectedIndex)
		{
		case 0:
			uow->Creator()->DeleteCreator(uow->Creator()->GetCreatorById(id));
			break;
		case 1:
			uow->Feature()->DeleteFeature(uow->Feature()->GetFeatureById(id));
			break;
		case 2:
			uow->Os()->DeleteOs(uow->Os()->GetOsById(id));
			break;
		case 3:
			uow->Processor()->DeleteProcessor(uow->Processor()->GetProcessorById(id));
			break;
		case 4:
			uow->Shop()->DeleteShop(uow->Shop()->GetShopById(id));
			break;
		case 5:
			uow->ShopHasPhone()->DeleteShopHasPhone(uow->ShopHasPhone()->GetShopHasPhoneById(id));
			break;
		case 6:
			uow->User()->DeleteUser(uow->User()->GetUserByUsername(username));
			break;
		default:
			break;
		}
		CallSelected();
	}
	private: System::Void StuffForm_Load(System::Object^  sender, System::EventArgs^  e) {
		InitCombo();
		comboBox1->SelectedIndex = 0;
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		CallSelected();
		label1->Text = comboBox1->SelectedItem->ToString();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ username;
		int id;
		if (comboBox1->SelectedIndex > 5)
		{
			username = dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value->ToString();
		}
		else
		{
			id = System::Convert::ToInt32(dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value);
		}
		switch (comboBox1->SelectedIndex)
		{
		case 0:
		{
			EditCreator^ formCreator = gcnew EditCreator(uow, id);
			formCreator->ShowDialog();
			break;
		}
		case 1:
		{
			EditFeature^ formFeature = gcnew EditFeature(uow, id);
			formFeature->ShowDialog();
			break;
		}
		case 2:
		{
			EditOs^ form = gcnew EditOs(uow, id);
			form->ShowDialog();
			break;
		}
		case 3:
		{
			EditProcessor^ form = gcnew EditProcessor(uow, id);
			form->ShowDialog();
			break;
		}
		case 4:
		{
			EditShop^ form = gcnew EditShop(uow, id);
			form->ShowDialog();
			break;
		}
		case 5:
		{
			EditOffer^ form = gcnew EditOffer(uow, id);
			form->ShowDialog();
			break;
		}
		case 6:
		{
			EditUser^ form = gcnew EditUser(uow, username);
			form->ShowDialog();
			break;
		}
		}
		CallSelected();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		switch (comboBox1->SelectedIndex)
		{
		case 0: {
			EditCreator^ formCreator = gcnew EditCreator(uow);
			formCreator->ShowDialog();
			break; }
		case 1: {
			EditFeature^ formFeature = gcnew EditFeature(uow);
			formFeature->ShowDialog();
			break; }
		case 2: {
			EditOs^ form = gcnew EditOs(uow);
			form->ShowDialog();
			break;
		}
		case 3: {
			EditProcessor^ form = gcnew EditProcessor(uow);
			form->ShowDialog();
			break;
		}
		case 4: {
			EditShop^ form = gcnew EditShop(uow);
			form->ShowDialog();
			break;
		}
		case 5: {
			EditOffer^ form = gcnew EditOffer(uow);
			form->ShowDialog();
			break;
		}
		case 6: {
			EditUser^ form = gcnew EditUser(uow);
			form->ShowDialog();
			break;
		}
		}
		CallSelected();
	}
};
}
