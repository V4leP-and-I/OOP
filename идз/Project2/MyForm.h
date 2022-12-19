#pragma once


namespace Redact {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class Redactor : public System::Windows::Forms::Form // �������� �����, ����� ������� ����� ����������� ��� ���������
	{
	public:
		Redactor(void)
		{
			InitializeComponent(); //������������ �����������
			openFileDialog1->Filter = "����� ����������� (*.bmp, *.jpg, *.png)|*.bmp; *.jpg; *.png";
			saveFileDialog1->Filter = "����� ����������� (*.bmp, *.jpg, *.png)|*.bmp; *.jpg; *.png";
		}
	protected:
		~Redactor()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ ������;
	private: System::Windows::Forms::Button^ �����;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ �����;
	private: System::Windows::Forms::Button^ ����2;
	private: System::Windows::Forms::Button^ ����;
	private: System::Windows::Forms::Button^ �������;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Button^ clear_all;
	private: System::Windows::Forms::Button^ OK;
	private: System::Windows::Forms::Button^ save_picture;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// ��������� ����� ��� ��������� ������������ 
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Redactor::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->OK = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->������ = (gcnew System::Windows::Forms::Button());
			this->����� = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->����� = (gcnew System::Windows::Forms::Button());
			this->����2 = (gcnew System::Windows::Forms::Button());
			this->���� = (gcnew System::Windows::Forms::Button());
			this->������� = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->clear_all = (gcnew System::Windows::Forms::Button());
			this->save_picture = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(322, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(941, 577);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Redactor::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Redactor::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Redactor::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Redactor::pictureBox1_MouseUp);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->OK);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->������);
			this->groupBox1->Controls->Add(this->�����);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(290, 187);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"�����";
			// 
			// OK
			// 
			this->OK->Location = System::Drawing::Point(129, 121);
			this->OK->Name = L"OK";
			this->OK->Size = System::Drawing::Size(52, 32);
			this->OK->TabIndex = 5;
			this->OK->Text = L"OK";
			this->OK->UseVisualStyleBackColor = true;
			this->OK->Click += gcnew System::EventHandler(this, &Redactor::OK_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 105);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"������";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(29, 128);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(86, 26);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ������
			// 
			this->������->Location = System::Drawing::Point(120, 36);
			this->������->Name = L"������";
			this->������->Size = System::Drawing::Size(86, 47);
			this->������->TabIndex = 1;
			this->������->Text = L"������";
			this->������->UseVisualStyleBackColor = true;
			this->������->Click += gcnew System::EventHandler(this, &Redactor::Eraser_button);
			// 
			// �����
			// 
			this->�����->Location = System::Drawing::Point(15, 36);
			this->�����->Name = L"�����";
			this->�����->Size = System::Drawing::Size(75, 47);
			this->�����->TabIndex = 0;
			this->�����->Text = L"�����";
			this->�����->UseVisualStyleBackColor = true;
			this->�����->Click += gcnew System::EventHandler(this, &Redactor::Brush_button);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->�����);
			this->groupBox2->Controls->Add(this->����2);
			this->groupBox2->Controls->Add(this->����);
			this->groupBox2->Controls->Add(this->�������);
			this->groupBox2->Location = System::Drawing::Point(12, 229);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(230, 184);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"������";
			// 
			// �����
			// 
			this->�����->Location = System::Drawing::Point(15, 103);
			this->�����->Name = L"�����";
			this->�����->Size = System::Drawing::Size(86, 47);
			this->�����->TabIndex = 5;
			this->�����->Text = L"�����";
			this->�����->UseVisualStyleBackColor = true;
			this->�����->Click += gcnew System::EventHandler(this, &Redactor::line_button);
			// 
			// ����2
			// 
			this->����2->Location = System::Drawing::Point(120, 110);
			this->����2->Name = L"����2";
			this->����2->Size = System::Drawing::Size(75, 33);
			this->����2->TabIndex = 4;
			this->����2->Text = L"����";
			this->����2->UseVisualStyleBackColor = true;
			this->����2->Click += gcnew System::EventHandler(this, &Redactor::color_line_button);
			// 
			// ����
			// 
			this->����->Location = System::Drawing::Point(120, 36);
			this->����->Name = L"����";
			this->����->Size = System::Drawing::Size(86, 47);
			this->����->TabIndex = 1;
			this->����->Text = L"����";
			this->����->UseVisualStyleBackColor = true;
			this->����->Click += gcnew System::EventHandler(this, &Redactor::circle_button);
			// 
			// �������
			// 
			this->�������->Location = System::Drawing::Point(15, 36);
			this->�������->Name = L"�������";
			this->�������->Size = System::Drawing::Size(86, 47);
			this->�������->TabIndex = 0;
			this->�������->Text = L"�������";
			this->�������->UseVisualStyleBackColor = true;
			this->�������->Click += gcnew System::EventHandler(this, &Redactor::Square_button);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// clear_all
			// 
			this->clear_all->Location = System::Drawing::Point(58, 438);
			this->clear_all->Name = L"clear_all";
			this->clear_all->Size = System::Drawing::Size(148, 57);
			this->clear_all->TabIndex = 6;
			this->clear_all->Text = L"������� ��";
			this->clear_all->UseVisualStyleBackColor = true;
			this->clear_all->Click += gcnew System::EventHandler(this, &Redactor::clear_all_Click);
			// 
			// save_picture
			// 
			this->save_picture->Location = System::Drawing::Point(58, 514);
			this->save_picture->Name = L"save_picture";
			this->save_picture->Size = System::Drawing::Size(148, 57);
			this->save_picture->TabIndex = 7;
			this->save_picture->Text = L"��������� �������";
			this->save_picture->UseVisualStyleBackColor = true;
			this->save_picture->Click += gcnew System::EventHandler(this, &Redactor::save_picture_Click);
			// 
			// Redactor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1278, 601);
			this->Controls->Add(this->save_picture);
			this->Controls->Add(this->clear_all);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1471, 808);
			this->Name = L"Redactor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������� ����������� ��������";
			this->Load += gcnew System::EventHandler(this, &Redactor::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		Graphics^ canva; //�����
		List<Point>^ points; // ����� ��� ���������
		Pen^ pen; // �����
		bool draw; 
		Bitmap^ background; // ���
		Color color; // ����
		float size; // ������
		String^ filename; // ��� �����
		int brush_type; // ��� �����
	
	private:
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) // ���������� ������� ����������
		{
			color = Color::Black; // ���� ����� �������
			size = 1; // ������ ����� 1
			pen = gcnew Pen(color, size); // ������ ����� � ����� ���������
			points = gcnew List <Point>(); // �������������� �����
			brush_type = 1; // ��� ������� ������ ������

			// ���������� ������
			�����->BackColor = Color::LightBlue;
			������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�������->BackColor = Color::LightGray;
			����->BackColor = Color::LightGray;

			//������ �����������
			Bitmap^ Img = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			canva = Graphics::FromImage(Img); // ���������� �����
			pictureBox1->Image = Img; // ���������� �����������
			pictureBox1->BackColor = Color::White;

		}

		System::Void Brush_button(System::Object^ sender, System::EventArgs^ e) // ��������� �����
		{
			if (brush_type != 1) // ���� �� ���� �����
			{
				brush_type = 1;
			}
			color = Color::Black; // ���� - ������
			pen = gcnew Pen(color, size); // �������������� �����

			//���������� ������
			�����->BackColor = Color::LightBlue;
			������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�������->BackColor = Color::LightGray;
			����->BackColor = Color::LightGray;
		}
	
		System::Void Eraser_button(System::Object^ sender, System::EventArgs^ e) // ��������� �������
		{
			if (brush_type != 4)
			{
				{
					brush_type = 4;
				}
			}
			color = Color::White; // ���� - �����
			pen = gcnew Pen(color, size);

			//���������� ������
			������->BackColor = Color::LightBlue;
			�������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			����->BackColor = Color::LightGray;
		}

		System::Void Square_button(System::Object^ sender, System::EventArgs^ e) // ��������� ��������
		{
			if (brush_type != 2)
			{
				brush_type = 2;
			}
			�������->BackColor = Color::LightBlue;
			������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			����->BackColor = Color::LightGray;
		}

		System::Void circle_button(System::Object^ sender, System::EventArgs^ e) // ��������� �����
		{
			if (brush_type != 3)
			{
				brush_type = 3;
			}
			����->BackColor = Color::LightBlue;
			������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
		}

		System::Void line_button(System::Object^ sender, System::EventArgs^ e) // ��������� �����
		{
			if (brush_type != 5)
			{
				brush_type = 5;
			}
			�����->BackColor = Color::LightBlue;
			������->BackColor = Color::LightGray;
			�����->BackColor = Color::LightGray;
			�������->BackColor = Color::LightGray;
			����->BackColor = Color::LightGray;
		}

		System::Void color_line_button(System::Object^ sender, System::EventArgs^ e) // ���������� ������ �����
		{
			colorDialog1->ShowDialog(); // ��������� ���� �����
			color = colorDialog1->Color; // ���������� ����
			����2->BackColor = color; // ����������� ������ � ����
			pen = gcnew Pen(color, size); // ����� ����� ��������� �����
		}

		System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) // ������� ���������
		{
			switch (brush_type)
			{
			case 1:
				if (points->Count > 1) //������ ������
					canva->DrawLines(pen, points->ToArray());
				break;

			case 2: // ������ �������
				canva->DrawRectangle(pen, MousePosition.X - 435, MousePosition.Y - 170, Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown1->Value));
				break;

			case 3: // ������ ����
				canva->DrawEllipse(pen, MousePosition.X - 435, MousePosition.Y - 170, Convert::ToInt32(numericUpDown1->Value), Convert::ToInt32(numericUpDown1->Value));
				break;
			case 4: // ������ ��������
				if (points->Count > 1)
					canva->DrawLines(pen, points->ToArray());
				break;
			case 5: // ������ ������
				if (points->Count > 1)
					canva->DrawLines(pen, points->ToArray());
			default:
				break;
			}
		}

		System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) // ���������� ������� �������� ����
		{
			if ((draw && points->Contains(Point(e->X, e->Y)) == false) && brush_type != 5) // �������� ����� �� ��������, ���� �� ������ �����, �� �����
			{
				if (e->Button == System::Windows::Forms::MouseButtons::Left) // �������� ������� ����� ������ ����
				{
					points->Add(e->Location); // ���������� �����
				}
				pictureBox1->Invalidate(); // ��������������
			}
		}

		System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) // ���������� ������� ���������� ������ ����
		{
			draw = false; // �������� ������ ������
			pictureBox1->Invalidate(); // ������������
		}

		System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) // ��������� ������� ������ ����
		{
			if (brush_type == 1 || brush_type == 4)//���� ������ ������ ��� ��������
			{
				points->Clear(); // ������� ������ �����
				points->Add(e->Location); // ���������� ��� �����
				draw = true; // �������� �����
			}
			else if (brush_type == 5) // ���� ������ �����
			{
				points->Add(e->Location);
				draw = true;
			}
			else
			{ // ���������� ������� ����
				MousePosition.X = e->Location.X;
				MousePosition.Y = e->Location.Y;
			}

			pictureBox1->Invalidate(); // ��������������
		}

		System::Void clear_all_Click(System::Object^ sender, System::EventArgs^ e) // ���������� ������� ������ �������� ������
		{
			points->Clear(); // ������� �����
			canva->Clear(Color::White); // ������� �����
			pictureBox1->Invalidate(); // ��������������
		}

		System::Void OK_Click(System::Object^ sender, System::EventArgs^ e) // ���������� ������� ������ OK - ����� ������ �����
		{
			size = Convert::ToInt32(numericUpDown1->Value); // ����������� ����� ������ �����
			pen = gcnew Pen(color, size); // �������������� �����
		}

		System::Void save_picture_Click(System::Object^ sender, System::EventArgs^ e) // ���������� ������� ������ ���������� �������
		{
			String^ filename;
			saveFileDialog1->ShowDialog(); // ��������� ���� ��� ����������
			filename = saveFileDialog1->FileName; // ��������� �������� �����������

			if (filename == "") // ���� ���� ���� ������� ������ �� ������
				return;

			Bitmap^ image = gcnew Bitmap(pictureBox1->Image); // ������ ����������� ������, ����������� ��� ������� �����������
			image->Save(filename); // ���������

			MessageBox::Show("����������� ���������!", "�������.");

			return System::Void();
		}
};
}
