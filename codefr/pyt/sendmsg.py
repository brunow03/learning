import smtplib
from email.message import EmailMessage

def send_email(subject, body, to_email):
    # Create EmailMessage object
    msg = EmailMessage()
    msg.set_content(body)
    msg['Subject'] = subject
    msg['From'] = 'bruno.mendes.333@hotmail.com'  # Update with your Hotmail/Outlook.com email
    msg['To'] = to_email

    # SMTP server settings for Hotmail/Outlook.com
    smtp_server = 'smtp-mail.outlook.com'
    smtp_port = 587
    smtp_username = 'bruno.mendes.333@hotmail.com'  # Update with your Hotmail/Outlook.com email
    smtp_password = 'antoinedelavoisi'  # Update with your Hotmail/Outlook.com password

    # Create SMTP session
    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(smtp_username, smtp_password)
        server.send_message(msg)
        print("Email sent successfully!")
    except Exception as e:
        print(f"Failed to send email. Error: {e}")
    finally:
        server.quit()

# Usage
subject = 'Hello'
body = 'Hello there, this is a test email!'
to_email = 'bruno.mendes.003@gmail.com'
send_email(subject, body, to_email)
