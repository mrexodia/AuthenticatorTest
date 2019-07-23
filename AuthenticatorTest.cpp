#include <libcppotp/bytes.h>
#include <libcppotp/otp.h>

#include <unistd.h>

using namespace CppTotp;

static std::string normalizedBase32String(const std::string & unnorm)
{
	std::string ret;

	for (char c : unnorm)
	{
		if (c == ' ' || c == '\n' || c == '-')
		{
			// skip separators
		}
		else if (std::islower(c))
		{
			// make uppercase
			char u = std::toupper(c);
			ret.push_back(u);
		}
		else
		{
			ret.push_back(c);
		}
	}

	return ret;
}

int main()
{
	// http://security-totp.appspot.com
	auto key = "ODXQMFKYEOAFQCA46VG6HOROJAJOAVTO";
	std::string normalizedKey = normalizedBase32String(key);
	Bytes::ByteString qui = Bytes::fromUnpaddedBase32(normalizedKey);

	while (1)
	{
		uint32_t p = totp(qui, time(NULL), 0, 30, 6);
		printf("%06u (%2us remain)\r", p, 30 - (time(NULL) % 30));
		fflush(stdout);
		sleep(1);
	}
}