import smtplib
import ssl
import sys


def main():
    port = 465
    email_sender = "belicoders1@gmail.com"
    email_receiver = "tomas.trejosg@autonoma.edu.co"
    smtp_server = "smtp.gmail.com"
    password = "iiop ygom nzee bnwr"
    message = sys.argv[1]
    context = ssl.create_default_context()

    with smtplib.SMTP_SSL(smtp_server, port, context=context) as server:
        server.login(email_sender, password)
        server.sendmail(email_sender, email_receiver, message)


if __name__ == "__main__":
    main()
