#include <stdio.h>
#include <stdlib.h>


void start_html();
void fill_html(char class, char *ip_str);
void end_html();
void get_data(char *class, char *ip_str);

int main()
{
	char class;
	char ip_str[40]= "";

	get_data(&class, ip_str);
	start_html();
	fill_html(class, ip_str);
	end_html();

	
	return 0;	
}

void get_data (char *class, char *ip_str)
{
	char *get_data = getenv("QUERY_STRING");
	sscanf(get_data, "ip_entry=%s", ip_str);


	int start_ip;
	sscanf(ip_str, "%d", &start_ip);


	if (start_ip < 128)
		*class = 'A';
	else if (start_ip < 192)
		*class = 'B';
	else if (start_ip < 224)
		*class = 'C';
	else if (start_ip < 240)
		*class = 'D';
	else if (start_ip >= 240)
		*class = 'E';
	else
		*class = 'X';
}

void start_html()
{
	printf("Text-Content: text/html\n\n");
	printf(
"<html lang='en'>\n"
"	<head>\n"
"		<meta charset='UTF-8'>\n"
"		<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
"		<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n"
"		<title>Document</title>\n"
"		<link rel='stylesheet' href='assets/css/style.css'>\n"
"	</head>\n"
"	<body>\n"
"		<div class='container'>\n"
"			<div class='titre'>\n"
"				Ip-Class\n"
"			</div>\n"
"			<form action='main.cgi' method='get'>\n"
"				<input type='text' name='ip_entry' id='ip_entry' placeholder='Addresse Ip (ex: 192.168.43.1)'>\n"
"				<button type='submit' id='ip_valide'> Quelle classe ? </button>\n"
"			</form>\n"
"		</div>\n"
	);
}

void end_html()
{
	printf(
"		<script src='assets/js/jquery-3.4.1.js'></script>\n"
"		<script src='assets/js/script.js'></script>\n"
"	</body>\n"
"</html>\n"
	);
}


void fill_html(char class, char *ip_str)
{
	printf(
"<div class='container resultok' id='result' style='display :none;'>\n"
"	<p>%s</p>\n"
"	<p>classe</p>\n"
"	<h1>%c</h1>\n"
"</div>\n"
	,ip_str, class	
);
}