#include <stdexcept>
#include <string>
#include <string_view>

#include <cstdint>
#include <cstdlib>

#include "../config.h"
#include "../lib.h"
#include "../arch/arch.h"
#include "os.h"
#include "os-lib.h"

namespace OS
{

	// ---------------------------------------

	Arch::Cpu *cpu;
	void boot(Arch::Cpu *cpu)
	{
		OS::cpu = cpu;
		terminal_println(cpu, Terminal::Command, "fds");
		terminal_println(cpu, Terminal::Command, "Type commands here");
		terminal_println(cpu, Arch::Terminal::Type::App, "Apps output here");
		terminal_println(cpu, Arch::Terminal::Type::Kernel, "Kernel output here");
	}

	// ---------------------------------------

	void interrupt(const Arch::InterruptCode interrupt)
	{
		uint16_t key = cpu->read_io(IO_Port::TerminalReadTypedChar);
		switch (key)
		{
		case 'q':
			terminal_print(cpu, Terminal::Command, (char)key);
			break;
		case 'k':
			cpu->turn_off();
			break;
		}
	}

	// ---------------------------------------

	void syscall()
	{
	}

	// ---------------------------------------

} // end namespace OS
