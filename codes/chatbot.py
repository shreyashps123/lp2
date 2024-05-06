import nltk
from nltk.chat.util import Chat, reflections
pairs = [
    ['need help', ['How can I assist you?']],
    ['what is chatbot', ['A chatbot is a program designed to simulate conversation with human users. How can I assist you further?']],
    ['hi', ['Hello!', 'Hi there!', 'Howdy!']],
    ['hello', ['Hello!', 'Hi there!', 'Howdy!']],
    ['how are you', ['I am functioning well, thank you for asking.', 'I am just a program, so I do not have feelings, but I am here to help you.']],
    ['what can you do', ['I can help you with various tasks such as answering questions, providing information, or just having a chat. Feel free to ask me anything!']],
    ['exit', ['Goodbye!', 'See you later!', 'Bye!']]
]

chatbot = Chat(pairs, reflections)

print("Welcome! I'm your chatbot. How can I assist you today?")
while True:
    user_input = input("You: ")
    response = chatbot.respond(user_input)
    print("Chatbot:", response)
    if user_input.lower() == 'exit':
        break
