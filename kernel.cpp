class Test {
private:
	char m_ch;
public:
	Test(char ch) {
		m_ch = ch;
	}

	void doIt() {
		char *vga = (char *)0xb8000;
		vga[0] = m_ch;
		vga[1] = 0x1f;
	}
};

extern "C" void main() {
	Test test('k');
	test.doIt();
}
